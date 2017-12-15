#include "HealthBar.h"

HealthBar::HealthBar() : Sprite(texturemanager->GetTexture("health_200"))
{

}

HealthBar::~HealthBar()
{

}

void HealthBar::Update()
{
	int health = Util::GetInstance()->GetHealth();
	string name = "health_" + to_string(health);
	//LPCSTR name;
	//switch (health)
	//{
	//	case 0:
	//		name = "health_0";
	//		break;
	//	case 50:
	//		name = "health_50";
	//		break;
	//	case 100:
	//		name = "health_100";
	//		break;
	//	case 150:
	//		name = "health_150";
	//		break;
	//	case 200:
	//		name = "health_200";
	//		break;
	//	default:
	//		name = "health_0";
	//		break;
	//}
	SetTexture(texturemanager->GetTexture(name));
}