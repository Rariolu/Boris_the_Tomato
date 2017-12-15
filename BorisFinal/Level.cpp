#include "Level.h"
#include"SceneManager.h"
#include"NumberSprite.h"

Level::Level() : Scene("Level_Background")
{

}

Level::~Level()
{
	Scene::~Scene();
}

void Level::Initialise(SDL_Renderer* renderer)
{
	SetMusicName("levelmusic");
	Scene::Initialise(renderer);
	descenderXPositions.clear();
	descenderXPositions.push_back(50);
	descenderXPositions.push_back(250);
	descenderXPositions.push_back(650);
	descenderXPositions.push_back(800);
	descenders.clear();

	pointscounter = new PointsCounter();
	pointscounter->SetPosition(350, 50);
	vector<NumberSprite*>* ns = pointscounter->GetNumberSprites();
	for (vector<NumberSprite*>::iterator i = ns->begin(); i < ns->end(); i++)
	{
		AddSprite((*i), 10);
	}

	init_leaves();

	bottom = AddSprite(textureManager->GetTexture("bottom"), 10);//new Sprite(textureManager->GetTexture("bottom"));
	bottom->SetPosition(0, 525);
	bottom->SetActive(true);
	healthbar = new HealthBar();
	healthbar->SetPosition(700, 10);
	healthbar->SetActive(true);
	AddSprite(healthbar, 11);
}

void Level::init_leaves()
{
	const float leafY = 350;
	leaves.clear();
	vector<int> positions;
	positions.push_back(0);
	positions.push_back(200);
	positions.push_back(600);
	positions.push_back(750);
	for (int i = 0; i < 4; i++)
	{
		Leaf* leaf = new Leaf();
		leaf->SetPosition((float)positions.at(i), leafY);
		leaf->SetActive(true);
		AddSprite(leaf, 6);
		leaves.push_back(leaf);
	}
}

Descender* Level::AddDescender()
{
	int nameindex = Operations::RandomNumber(0, 20);
	if (nameindex > 2)
	{
		if (nameindex % 3 != 0)
		{
			nameindex = 2;
		}
		else
		{
			nameindex = 0;
		}
	}
	DescenderType type = static_cast<DescenderType>(nameindex);
	int xindex = Operations::RandomNumber(0, descenderXPositions.size()-1);
	int x = descenderXPositions.at(xindex);
	Descender* d = new Descender(type);
	d->SetPosition((float)x, (float)0);
	while (CollidesWithADescender(d))
	{
		//cout << "Collision detected." << endl;
		d = new Descender(type);
		xindex = Operations::RandomNumber(0, 2);
		x = descenderXPositions.at(xindex);
		d->SetPosition((float)x, (float)0);
	}
	//if (LayerExists(4))
	//{
	//	for (vector<Descender*>::iterator descender = descenders.begin(); descender < descenders.end(); descender++)
	//	{ 
	//		if (d->CollidesWith((*descender)))
	//		{
	//			return AddDescender();//d;
	//		}
	//	}
	//}
	AddSprite(d, 4);
	d->SetActive(true);
	descenders.push_back(d);
	return d;
}

bool Level::CollidesWithADescender(Sprite* d)
{
	if (LayerExists(4))
	{
		for (vector<Descender*>::iterator descender = descenders.begin(); descender < descenders.end(); descender++)
		{
			if (d->CollidesWith((*descender)))
			{
				return true;
			}
		}
	}
	return false;
}

bool Level::GetInput()
{
	SDL_Event event;
	Scene* pauseMenu;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					    pauseMenu = SceneManager::GetInstance()->GetScene("PauseMenu");
						if (pauseMenu)
						{
							pauseMenu->Initialise(GetRenderer());
							string run = pauseMenu->Run();
							if (run == "[EXIT GAME]")
							{
								return false;
							}
							Sound* m = soundManager->GetSound(GetMusicName());
							Util::GetInstance()->SetCurrentMusic(GetMusicName());
							if (m)
							{
								m->Play();
							}
						}
						break;
					case SDLK_0:
						GameOver();
						break;
					case SDLK_a:
						leaves.at(0)->AlternateLeafState();
						break;
					case SDLK_s:
						leaves.at(1)->AlternateLeafState();
						break;
					case SDLK_d:
						leaves.at(2)->AlternateLeafState();
						break;
					case SDLK_f:
						leaves.at(3)->AlternateLeafState();
						break;
				}
				break;
			default:
				break;
		}
	}
	return true;
}

void Level::Update(float deltaTime)
{
	pointscounter->Update(deltaTime);
	spawnWait -= deltaTime;
	for (vector<Descender*>::iterator i = descenders.begin(); i < descenders.end(); i++)
	{
		(*i)->Update(deltaTime);
		bool leaffcollision = false;// = LeafCollision((*i), leaf) || LeafCollision((*i), leaf1) || LeafCollision((*i), leaf2) || LeafCollision((*i), leaf3);

		for (vector<Leaf*>::iterator leaf = leaves.begin(); leaf < leaves.end(); leaf++)
		{
			if (LeafCollision((*i), (*leaf)))
			{
				leaffcollision = true;
				break;
			}
		}
		if (!(*i)->IsActive() || leaffcollision || (*i)->CollidesWith(bottom))
		{
			if ((*i)->CollidesWith(bottom))
			{
				if ((*i)->GetDescenderType() == SUNLIGHT)
				{
					soundManager->GetSound("damage")->Play();
					Util::GetInstance()->IncreaseHealth(-50);
				}
			}
			else if (leaffcollision)
			{
				switch ((*i)->GetDescenderType())
				{
					case SUNLIGHT:
						soundManager->GetSound("collection")->Play();
						Util::GetInstance()->IncreasePoints(5);
						break;
					case WATER:
						soundManager->GetSound("collection")->Play();
						Util::GetInstance()->IncreasePoints(10);
						Util::GetInstance()->IncreaseHealth(50);
						break;
					case SCISSORS:
						soundManager->GetSound("scissors")->Play();
						for (vector<Leaf*>::iterator leaf = leaves.begin(); leaf < leaves.end(); leaf++)
						{
							if (LeafCollision((*i), (*leaf)))
							{
								(*leaf)->SetActive(false);
								break;
							}
						}
						break;
				}
			}
			(*i)->SetActive(false);
			if (i < descenders.end() - 1)
			{
				i = DeleteDescender(i);
			}
		}
		
	}
	int r = Operations::RandomNumber(0, 5);
	if (r == 0 && spawnWait <= 0)
	{
		AddDescender();
		spawnWait = 20;
	}
	healthbar->Update();
	if (Util::GetInstance()->GetHealth() <= 0)
	{
		GameOver();
	}
}

void Level::GameOver()
{
	SetNextScene("gameover");
}

bool Level::LeafCollision(Descender* d, Leaf* l)
{
	return l->CollidesWith(d) && l->GetLeafState() == PROTRUDING;// && l->IsActive() && d->IsActive();
}

vector<Descender*>::iterator Level::DeleteDescender(vector<Descender*>::iterator d)
{
	try
	{
		DeleteSprite((*d), 4);
		d = descenders.erase(d);
		//cout << "A descender was successfully deleted ^_^." << endl;
		return d;
	}
	catch (exception err)
	{
		cout << "Tried to delete a descender but this awkward problem came up \"" << err.what() << "\"" << endl;
		return d;
	}
}