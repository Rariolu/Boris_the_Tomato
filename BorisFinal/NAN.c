/* GIMP RGBA C-Source image dump (NAN.c) */


//A struct which is used to represent a null texture (i.e. a texture which should've been loaded from memory but couldn't be because of an invalid file path).

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[50 * 33 * 4 + 1];
} NonApplicableTexture = {
  50, 33, 4,
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\261\256\254\377\237\237\237\377\240\240\240\377\237\237\237\377\253\256"
  "\260\377\304\304\304\377\305\305\305\377\253\251\247\377\237\237\240\377"
  "\240\240\240\377\240\240\240\377\252\255\257\377\304\304\304\377\303\303"
  "\303\377\276\275\274\377\244\243\242\377\240\240\240\377\240\240\240\377"
  "\240\240\240\377\240\240\240\377\240\240\240\377\237\237\237\377\265\267"
  "\272\377\304\304\304\377\303\303\303\377\301\300\277\377\246\245\244\377"
  "\240\240\240\377\240\240\240\377\237\237\236\377\262\265\267\377\304\304"
  "\304\377\304\305\305\377\245\243\241\377\237\237\240\377\240\240\240\377"
  "\237\240\241\377\271\272\273\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\237\232\226\377|||\377~~~\377}}}\377\201\206\213\377\307\307\306"
  "\377\306\307\307\377\225\220\212\377|}}\377~~~\377~}}\377\222\227\234\377"
  "\306\305\305\377\303\303\303\377\267\264\262\377\203\202\200\377~~~\377~"
  "~~\377~~~\377~~~\377~~~\377}}|\377\235\243\247\377\305\305\305\377\303\303"
  "\303\377\277\275\273\377\212\210\206\377~~~\377~~~\377}}|\377\215\222\230"
  "\377\307\307\306\377\306\306\306\377\211\204~\377}}}\377~~~\377|~\200\377"
  "\257\261\263\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\240\233"
  "\226\377}~~\377\177\177\177\377\177\177\177\377|{{\377\262\267\275\377\310"
  "\307\307\377\226\221\213\377~~\177\377\177\177\177\377\177\177\177\377\223"
  "\230\235\377\305\305\305\377\303\303\303\377\261\260\255\377\201\200\177"
  "\377\177\177\177\377\177\177\177\377\177\177\177\377\177\177\177\377\177"
  "\177\177\377\177\177~\377\222\227\233\377\306\306\305\377\303\303\303\377"
  "\277\275\273\377\213\211\210\377\177\177\177\377\177\177\177\377\177\177"
  "\177\377\203\204\204\377\273\276\302\377\306\306\306\377\212\205\200\377"
  "~~\177\377\177\177\177\377~\177\201\377\257\261\263\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\240\233\226\377}~~\377\177\177\177\377\177\177"
  "\177\377~~}\377\224\231\236\377\312\312\312\377\226\221\213\377~~\177\377"
  "\177\177\177\377\177\177\177\377\223\230\235\377\305\305\305\377\303\303"
  "\303\377\254\251\246\377~}}\377\177\177\177\377\177\177\177\377\177\177\177"
  "\377\177\177\177\377\177\177\177\377\177\177\177\377\213\215\220\377\303"
  "\304\306\377\303\303\303\377\277\275\273\377\213\211\210\377\177\177\177"
  "\377\177\177\177\377\177\177\177\377\200\201\201\377\252\255\260\377\306"
  "\306\307\377\212\205\200\377~~\177\377\177\177\177\377~\177\201\377\257\261"
  "\263\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\240\233\226\377"
  "}~~\377\177\177\177\377\177\177\177\377\177\177\177\377\204\205\207\377\302"
  "\305\310\377\226\221\213\377~~\177\377\177\177\177\377\177\177\177\377\223"
  "\230\235\377\305\305\305\377\303\303\303\377\245\241\235\377~~~\377\177\177"
  "\177\377\177\177\177\377\200\200\200\377\177\177\177\377\177\177\177\377"
  "\177\177\177\377\210\212\213\377\275\300\302\377\303\303\303\377\277\275"
  "\273\377\213\211\210\377\177\177\177\377\177\177\177\377\177\177\177\377"
  "\177\177\177\377\231\234\237\377\305\305\306\377\212\205\200\377~~\177\377"
  "\177\177\177\377~\177\201\377\257\261\263\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\240\233\226\377}~~\377\177\177\177\377\177\177\177\377"
  "\177\177\177\377\201\202\202\377\262\265\271\377\226\221\214\377~~\177\377"
  "\177\177\177\377\177\177\177\377\223\230\235\377\305\305\305\377\303\303"
  "\303\377\234\231\224\377~~~\377\177\177\177\377~~~\377\221\221\221\377~~"
  "~\377\177\177\177\377\177\177\177\377\205\206\207\377\267\272\274\377\303"
  "\303\303\377\277\275\273\377\213\211\210\377\177\177\177\377\177\177\177"
  "\377\177\177\177\377\177\177\177\377\211\214\217\377\302\303\303\377\212"
  "\205\200\377~~\177\377\177\177\177\377~\177\201\377\257\261\263\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\240\233\226\377}~~\377\177\177\177"
  "\377\177\177\177\377\177\177\177\377\177\177\177\377\240\244\250\377\225"
  "\221\214\377~~\177\377\177\177\177\377\177\177\177\377\223\230\235\377\305"
  "\305\305\377\303\303\303\377\224\220\213\377~~~\377\177\177\177\377}}}\377"
  "\237\243\244\377\202}|\377\177\177\177\377\177\177\177\377\202\203\204\377"
  "\262\264\267\377\303\303\303\377\277\275\273\377\213\211\210\377\177\177"
  "\177\377\177\177\177\377\177\177\177\377\177\177\177\377|}\177\377\267\273"
  "\277\377\212\205\200\377~~\177\377\177\177\177\377~\177\201\377\257\261\263"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\240\233\226\377}~~\377"
  "\177\177\177\377\177\177\177\377\177\177\177\377\177\177\177\377\217\223"
  "\227\377\222\216\211\377~~\177\377\177\177\177\377\177\177\177\377\223\230"
  "\235\377\305\305\305\377\303\302\302\377\212\207\203\377~\177\177\377\177"
  "\177\177\377|||\377\251\257\264\377\210\203}\377~\177\177\377\177\177\177"
  "\377~\200\201\377\255\257\261\377\303\303\303\377\277\275\273\377\213\211"
  "\210\377\177\177\177\377\177\177\177\377\177\177\177\377\177\177\177\377"
  "}}|\377\234\242\250\377\214\207\201\377~~\177\377\177\177\177\377~\177\201"
  "\377\257\261\263\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\240"
  "\233\226\377}~~\377\177\177\177\377\177\177\177\377\177\177\177\377\177\177"
  "\177\377\201\204\207\377\215\212\206\377~~\177\377\177\177\177\377\177\177"
  "\177\377\223\230\235\377\305\305\305\377\303\302\300\377\202~{\377\177\177"
  "\177\377\177\177\177\377|||\377\264\271\275\377\217\211\204\377~~~\377\177"
  "\177\177\377}}~\377\244\250\253\377\303\303\303\377\277\275\273\377\213\211"
  "\210\377\177\177\177\377\177\177\177\377\177\177\177\377\177\177\177\377"
  "\177~~\377\204\207\215\377\213\210\203\377~~\177\377\177\177\177\377~\177"
  "\201\377\257\261\263\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\240\233\226\377}~~\377\177\177\177\377\177\177\177\377\177\177\177\377\177"
  "\177\177\377\177\177\177\377\200\200\200\377\177\177\177\377\177\177\177"
  "\377\177\177\177\377\223\230\235\377\306\306\306\377\300\274\266\377{{{\377"
  "\177\177\177\377\177\177\177\377|\177\201\377\274\276\277\377\226\221\213"
  "\377}~~\377\177\177\177\377~~~\377\232\236\243\377\303\303\303\377\277\275"
  "\273\377\213\211\210\377\177\177\177\377\177\177\177\377\177\177\177\377"
  "\177\177\177\377\177\177\177\377\177~\177\377\200\200\200\377\177\177\177"
  "\377\177\177\177\377~\177\201\377\257\261\263\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\240\233\226\377}~~\377\177\177\177\377\177\177\177"
  "\377\177\177\177\377\177\177\177\377\177\177\177\377\177\177\177\377\177"
  "\177\177\377\177\177\177\377\177\177\177\377\223\230\235\377\307\307\307"
  "\377\264\256\251\377{{|\377\177\177\177\377\177\177\177\377\201\204\207\377"
  "\276\277\300\377\236\231\224\377}}}\377\177\177\177\377~~~\377\220\224\230"
  "\377\303\303\303\377\277\275\273\377\213\211\210\377\177\177\177\377\177"
  "\177\177\377\177\177\177\377\177\177\177\377\177\177\177\377\177\177\177"
  "\377\177\177\177\377\177\177\177\377\177\177\177\377~\177\201\377\257\261"
  "\263\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\240\233\226\377"
  "}~~\377\177\177\177\377~~~\377\215\215\215\377~~~\377\177\177\177\377\177"
  "\177\177\377\177\177\177\377\177\177\177\377\177\177\177\377\223\230\235"
  "\377\307\310\310\377\250\242\235\377||}\377\177\177\177\377\177\177\177\377"
  "\206\211\214\377\300\301\302\377\251\243\236\377|}}\377\177\177\177\377\177"
  "~~\377\206\213\217\377\303\303\303\377\277\275\273\377\213\211\210\377\177"
  "\177\177\377\177\177\177\377~~~\377\216\216\216\377~~~\377\177\177\177\377"
  "\177\177\177\377\177\177\177\377\177\177\177\377~\177\201\377\257\261\263"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\240\233\226\377}~~\377"
  "\177\177\177\377}}}\377\241\244\246\377\203~}\377\177\177\177\377\177\177"
  "\177\377\177\177\177\377\177\177\177\377\177\177\177\377\223\230\235\377"
  "\310\310\311\377\234\227\221\377}}~\377\177\177\177\377\177\177\177\377\206"
  "\210\212\377\251\251\252\377\236\233\230\377}}}\377\177\177\177\377\177\177"
  "\177\377|\177\204\377\302\303\303\377\277\275\273\377\213\211\210\377\177"
  "\177\177\377\177\177\177\377|||\377\244\247\251\377\200}|\377\177\177\177"
  "\377\177\177\177\377\177\177\177\377\177\177\177\377~\177\201\377\257\261"
  "\263\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\240\233\226\377"
  "}~~\377\177\177\177\377}}|\377\241\246\253\377\233\225\220\377}}~\377\177"
  "\177\177\377\177\177\177\377\177\177\177\377\177\177\177\377\223\230\235"
  "\377\311\311\312\377\221\212\205\377~~\177\377\177\177\177\377\177\177\177"
  "\377\177\177\177\377~~~\377~~~\377\177\177\177\377\177\177\177\377\177\177"
  "\177\377{z{\377\267\276\301\377\300\275\273\377\213\211\210\377\177\177\177"
  "\377\177\177\177\377|||\377\251\256\262\377\216\213\207\377\177\177\177\377"
  "\177\177\177\377\177\177\177\377\177\177\177\377~\177\201\377\257\261\263"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\240\233\226\377}~~\377"
  "\177\177\177\377}}|\377\237\245\251\377\266\261\253\377|{|\377\177\177\177"
  "\377\177\177\177\377\177\177\177\377\177\177\177\377\223\230\235\377\312"
  "\311\306\377\204\200~\377\177\177\177\377\177\177\177\377\177\177\177\377"
  "\177\177\177\377\177\177\177\377\177\177\177\377\177\177\177\377\177\177"
  "\177\377\177\177\177\377|{{\377\252\257\265\377\301\276\274\377\213\211\210"
  "\377\177\177\177\377\177\177\177\377|||\377\253\261\265\377\236\233\227\377"
  "\177~\177\377\177\177\177\377\177\177\177\377\177\177\177\377~\177\201\377"
  "\257\261\263\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\240\233"
  "\226\377}~~\377\177\177\177\377}}|\377\236\244\250\377\300\277\275\377\206"
  "\202\200\377\177\177\177\377\177\177\177\377\177\177\177\377\177\177\177"
  "\377\223\230\235\377\305\300\274\377~~\177\377\177\177\177\377\177\177\177"
  "\377\177\177\177\377\177~~\377|||\377|||\377\177\177\177\377\177\177\177"
  "\377\177\177\177\377}||\377\233\241\247\377\302\277\275\377\213\211\210\377"
  "\177\177\177\377\177\177\177\377|||\377\254\262\267\377\256\252\247\377\200"
  "\200\177\377\177\177\177\377\177\177\177\377\177\177\177\377~\177\201\377"
  "\257\261\263\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303"
  "\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377"
  "\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\240\233"
  "\226\377}~~\377\177\177\177\377}}|\377\236\244\250\377\303\302\301\377\225"
  "\222\216\377\177\177\177\377\177\177\177\377\177\177\177\377\177\177\177"
  "\377\224\231\236\377\273\267\262\377\177\177\177\377\177\177\177\377\177"
  "\177\177\377\177\177\177\377\210\212\214\377\263\264\265\377\261\260\256"
  "\377\177}|\377\177\177\177\377\177\177\177\377~}}\377\215\224\232\377\303"
  "\301\276\377\213\211\210\377\177\177\177\377\177\177\177\377|||\377\254\262"
  "\267\377\275\271\266\377\203\203\202\377\177\177\177\377\177\177\177\377"
  "\177\177\177\377~\177\201\377\257\261\263\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\240\233\226\377}~~\377\177\177\177\377}}|\377\236\244"
  "\250\377\305\304\304\377\245\242\236\377\177\177\177\377\177\177\177\377"
  "\177\177\177\377\177\177\177\377\224\231\236\377\262\256\251\377\177\177"
  "\177\377\177\177\177\377\177\177\177\377\177\177\177\377\216\220\223\377"
  "\300\301\302\377\275\274\273\377\202\177}\377\177\177\177\377\177\177\177"
  "\377\177\177~\377\201\205\213\377\303\302\277\377\213\211\210\377\177\177"
  "\177\377\177\177\177\377|||\377\254\262\266\377\310\307\305\377\215\211\206"
  "\377~\177\177\377\177\177\177\377\177\177\177\377~\177\201\377\257\261\263"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\240\233\226\377}~~\377"
  "\177\177\177\377}}|\377\236\244\250\377\305\304\304\377\265\261\256\377\202"
  "\201\201\377\177\177\177\377\177\177\177\377\177\177\177\377\224\231\237"
  "\377\250\244\240\377\177\177\177\377\177\177\177\377\177\177\177\377\177"
  "\177\177\377\221\224\227\377\300\301\302\377\275\274\273\377\206\203\200"
  "\377\177\177\177\377\177\177\177\377\177\177\177\377~~\200\377\274\275\277"
  "\377\213\212\210\377\177\177\177\377\177\177\177\377|||\377\254\262\266\377"
  "\307\307\307\377\247\241\234\377}}}\377\177\177\177\377\177\177\177\377~"
  "\177\201\377\257\261\263\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\250\244\241\377\215\215\216\377\216\216\216\377\215\215\214\377\247"
  "\253\256\377\304\304\304\377\302\300\275\377\223\222\222\377\216\216\216"
  "\377\216\216\216\377\216\216\216\377\237\243\247\377\250\245\241\377\216"
  "\216\216\377\216\216\216\377\216\216\216\377\216\216\216\377\237\242\244"
  "\377\302\302\303\377\277\276\276\377\226\224\222\377\216\216\216\377\216"
  "\216\216\377\216\216\216\377\216\216\216\377\265\267\271\377\230\227\225"
  "\377\216\216\216\377\216\216\216\377\214\214\214\377\261\265\271\377\305"
  "\305\305\377\276\273\266\377\213\214\214\377\216\216\216\377\216\216\216"
  "\377\215\217\220\377\264\265\267\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\304\305\305\377\306\306\306\377\306\306\306\377\306\306\306"
  "\377\305\304\304\377\303\303\303\377\303\303\303\377\306\306\306\377\306"
  "\306\306\377\306\306\306\377\306\306\306\377\305\305\305\377\304\305\305"
  "\377\306\306\306\377\306\306\306\377\306\306\306\377\306\306\306\377\305"
  "\305\305\377\303\303\303\377\303\303\303\377\305\306\306\377\306\306\306"
  "\377\306\306\306\377\306\306\306\377\306\306\306\377\304\304\304\377\305"
  "\305\305\377\306\306\306\377\306\306\306\377\306\306\306\377\304\304\304"
  "\377\303\303\303\377\303\304\304\377\306\306\306\377\306\306\306\377\306"
  "\306\306\377\306\306\306\377\304\304\304\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303"
  "\377\303\303\303\377\303\303\303\377\303\303\303\377\303\303\303\377\303"
  "\303\303\377\303\303\303\377\303\303\303\377",
};