#include <avr/pgmspace.h>
#include "NS_Rainbow.h"


const PROGMEM uint8_t IMAGE[][48]  = {{0,0,0,0,0,0,0,0,0,5,1,2,26,109,143,12,149,189,2,181,228,0,154,203,3,97,150,0,65,133,226,234,238,219,230,236,203,216,225,180,198,212,154,179,197,109,146,171},
{0,0,0,0,0,0,0,0,0,5,1,2,19,106,142,15,142,177,2,172,227,0,153,202,2,92,145,0,66,133,228,236,239,218,228,234,202,217,226,178,198,211,153,179,197,108,145,171},
{0,0,0,0,0,0,0,0,0,4,1,1,19,106,142,15,142,177,4,171,224,2,147,198,3,92,143,0,67,135,232,238,240,221,230,237,202,215,224,175,196,209,149,176,194,107,144,170},
{0,0,0,0,0,0,0,0,0,4,1,1,18,114,144,16,141,194,4,176,229,4,142,195,3,90,142,0,71,139,232,238,243,221,230,237,200,214,223,184,202,215,149,175,194,106,144,170},
{0,0,0,0,0,0,0,0,0,2,0,2,18,114,144,13,146,189,2,181,226,1,147,196,3,88,139,5,77,143,232,237,243,221,230,237,202,216,224,181,199,212,148,174,193,103,143,168},
{0,0,0,0,0,0,0,0,0,2,0,2,35,113,141,13,138,178,5,171,228,0,151,199,5,102,154,0,58,122,230,236,241,218,228,234,208,220,228,180,199,211,147,174,193,110,147,173},
{0,0,0,0,0,0,4,1,3,3,2,2,39,98,127,23,144,189,5,175,226,0,151,199,5,101,153,0,62,128,231,240,242,221,230,236,204,217,225,179,199,212,151,178,196,107,145,171},
{0,0,0,0,0,0,0,0,0,19,52,67,29,109,144,21,138,181,5,175,226,2,148,202,1,91,143,0,64,129,233,238,243,218,228,234,198,214,222,183,203,215,149,175,193,102,142,167},
{0,0,0,0,0,0,0,0,0,2,0,5,37,97,131,21,138,181,7,173,219,4,151,204,3,92,144,7,46,104,232,237,241,221,230,236,205,218,226,180,199,211,155,181,199,107,144,168},
{0,0,0,0,0,0,0,0,0,38,61,75,25,115,150,10,140,177,4,171,226,0,147,199,3,108,158,3,56,117,234,239,246,223,231,237,205,218,227,183,201,214,150,177,196,114,150,176},
{0,0,0,0,0,0,0,0,0,5,7,11,30,110,130,20,130,166,6,173,228,5,148,200,2,105,155,0,67,129,234,239,240,222,230,236,204,219,227,179,199,213,152,179,196,107,145,169},
{0,0,0,0,0,0,0,0,0,0,2,3,22,121,148,19,131,181,13,169,224,6,145,197,3,95,147,2,58,121,235,239,242,216,228,233,194,211,220,186,203,214,146,174,193,109,146,172},
{0,0,0,0,0,0,0,0,0,15,28,36,25,110,140,19,131,175,3,170,215,4,143,196,1,109,157,0,66,139,234,239,244,219,231,237,207,219,229,174,194,207,151,178,195,111,147,173},
{0,0,0,0,0,0,0,0,0,2,0,0,23,105,144,14,146,182,5,171,226,2,147,197,1,100,149,4,56,114,229,236,243,222,230,235,202,216,225,179,197,210,152,179,195,101,143,169},
{0,0,0,0,0,0,0,0,0,2,0,0,23,99,134,15,135,164,4,175,227,2,150,202,3,100,152,0,73,133,230,234,242,224,231,237,205,218,227,180,198,212,148,176,194,102,142,171},
{0,0,0,0,0,0,0,0,0,5,3,10,22,89,116,18,135,175,5,182,229,4,142,196,5,97,148,3,62,125,235,239,239,222,230,237,208,220,228,185,203,216,155,182,198,104,144,171},
{0,0,0,0,0,0,0,0,0,5,3,10,23,106,137,14,128,165,4,171,223,3,148,200,4,86,136,0,72,138,233,240,244,223,230,237,199,216,227,184,202,216,145,173,192,105,142,168},
{0,0,0,0,0,0,0,0,0,2,2,4,30,101,116,13,141,184,0,180,231,3,138,192,2,90,140,2,69,139,233,241,240,224,231,238,206,219,227,182,201,214,157,182,198,105,145,173},
{0,0,0,0,0,0,0,0,0,14,31,40,17,104,139,19,119,160,6,181,226,4,153,205,1,96,146,6,58,121,236,237,244,225,232,237,209,223,230,173,195,209,146,174,193,113,149,173},
{0,0,0,0,0,0,0,0,0,2,1,0,17,104,139,19,133,176,3,173,229,2,146,198,6,103,160,0,71,141,234,239,240,226,232,237,201,215,225,186,203,216,156,181,198,109,144,172},
{1,1,1,0,0,0,0,0,0,0,1,2,11,113,138,15,120,158,10,172,230,2,149,200,4,101,153,1,71,145,233,238,243,216,227,235,208,221,229,186,204,216,150,178,195,111,146,172},
{1,1,1,0,0,0,0,0,0,11,19,28,22,93,128,17,157,200,3,172,224,3,138,191,3,100,153,5,72,137,233,242,245,219,229,236,209,221,229,182,202,214,152,179,197,105,141,167},
{1,1,1,0,0,0,0,0,0,0,0,0,19,108,143,16,122,161,2,176,220,1,149,200,5,86,139,4,38,86,236,239,246,221,230,236,209,221,229,182,201,213,148,176,194,109,148,168},
{1,1,1,0,0,0,0,0,0,0,0,0,19,108,143,16,122,161,2,176,220,3,149,201,0,99,143,3,39,92,236,239,248,221,230,236,209,220,229,183,201,213,153,179,197,113,149,172},
{1,1,1,0,0,0,0,0,0,10,19,26,17,105,128,16,153,194,10,166,229,0,148,198,4,104,154,5,71,139,235,240,244,221,230,236,209,221,230,183,201,214,152,178,196,103,143,164},
{1,1,1,0,0,0,0,0,0,0,1,2,18,101,133,16,117,156,5,180,226,3,147,198,5,93,146,0,76,139,235,240,243,217,228,233,204,217,225,186,204,216,148,176,194,108,146,171},
{0,0,0,0,0,0,0,0,0,4,0,0,19,104,132,17,137,178,3,180,235,4,144,196,1,113,163,0,70,143,235,240,241,225,231,237,203,216,225,182,200,211,152,179,197,109,145,170},
{0,0,0,0,0,0,0,0,0,12,29,37,19,104,132,11,126,161,7,168,223,2,150,201,6,92,141,4,62,111,237,237,243,225,232,237,210,222,230,174,194,208,141,172,191,114,149,173},
{0,0,0,0,0,0,0,0,0,1,5,0,28,94,127,11,138,185,4,164,225,1,147,198,4,94,145,4,68,136,234,241,240,224,231,238,208,221,228,182,202,213,156,182,199,105,145,172},
{0,0,0,0,0,0,0,0,0,5,2,7,24,108,134,11,129,165,2,178,227,5,149,201,2,91,139,0,71,140,234,241,238,223,231,237,203,219,226,178,198,211,146,174,194,104,141,168},
{0,0,0,0,0,0,0,0,0,5,2,7,23,83,114,23,138,181,9,174,226,6,140,195,1,98,148,4,57,119,235,239,238,221,229,236,203,216,226,181,201,212,155,181,199,104,145,172},
{0,0,0,0,0,0,0,0,0,1,0,1,24,99,130,14,130,174,4,162,218,5,149,202,2,109,159,0,71,137,238,237,245,225,232,238,202,216,225,183,201,213,152,179,196,103,142,167},
{0,0,0,0,0,0,0,0,0,1,0,1,21,112,140,14,145,185,8,173,229,4,133,188,4,93,144,4,54,110,234,238,244,220,228,234,201,214,224,183,200,213,152,179,196,99,140,166},
{0,0,0,0,0,0,0,0,0,18,23,32,24,109,137,18,135,181,10,164,213,3,138,193,4,98,148,0,66,130,231,234,241,222,231,238,207,221,228,180,198,212,151,179,196,111,147,173},
{0,0,0,0,0,0,0,0,0,2,2,3,27,117,152,18,126,171,6,175,225,2,153,206,5,92,145,2,60,116,235,238,243,223,231,237,205,217,225,182,201,213,144,171,190,108,146,171},
{0,0,0,0,0,0,0,0,0,6,6,9,28,103,134,18,129,172,3,179,234,4,147,199,5,96,147,0,65,134,235,238,242,223,230,235,208,221,228,180,199,213,153,179,195,107,144,167},
{0,0,0,0,0,0,0,0,0,32,63,77,19,114,151,17,137,180,0,184,227,6,143,198,2,99,148,3,57,112,228,236,242,224,231,237,203,216,224,185,203,215,150,178,195,112,150,177},
{0,0,0,0,0,0,0,0,0,0,0,0,28,102,127,14,140,178,10,167,220,0,149,200,3,90,136,6,45,95,235,238,244,221,229,236,208,220,228,181,200,213,155,181,198,108,145,168},
{0,0,0,0,0,0,0,0,0,23,51,67,29,106,140,14,140,178,3,172,226,3,152,203,2,105,153,0,64,131,234,236,243,223,231,237,203,217,226,182,200,212,148,176,194,103,142,166},
{0,0,0,0,0,0,0,2,1,4,2,4,36,98,123,22,144,188,3,172,226,5,140,194,3,104,158,0,60,125,233,240,240,224,231,237,204,218,225,181,199,211,152,179,196,106,145,170},
{0,0,0,0,0,0,0,0,0,5,0,0,41,106,141,15,138,176,5,181,229,5,140,194,3,103,154,0,56,115,227,236,240,218,227,234,209,220,227,182,201,214,147,174,193,110,147,173},
{0,0,0,0,0,0,0,0,0,5,0,0,25,109,140,15,145,186,4,170,227,4,142,196,1,92,138,1,75,140,232,237,242,218,227,235,203,217,225,183,201,214,150,177,195,102,141,166},
{1,1,1,0,0,0,0,0,0,4,0,0,25,109,140,15,138,188,3,179,223,4,147,199,2,88,135,0,69,138,233,238,242,219,228,233,204,217,226,185,203,213,150,177,195,103,142,167},
{1,1,1,0,0,0,0,0,0,4,0,0,15,107,140,14,142,182,1,175,223,3,146,198,5,85,136,0,66,136,231,238,240,218,229,235,200,214,223,181,198,213,148,177,193,107,145,171},
{1,1,1,0,0,0,0,0,0,0,0,0,15,107,140,14,142,182,0,179,233,2,147,198,4,88,138,0,65,136,231,239,241,224,232,237,204,218,227,176,198,211,153,180,196,108,146,171},
{1,1,1,0,0,0,0,0,0,0,0,0,23,112,144,17,132,178,7,171,222,3,150,200,3,95,143,0,66,137,232,238,241,223,230,236,203,218,227,172,196,208,151,178,194,106,144,169},
{1,1,1,0,0,0,0,0,0,0,0,0,24,112,145,10,144,197,2,172,223,3,143,195,1,100,146,0,67,136,234,238,241,223,230,237,206,217,227,180,200,213,155,179,197,108,145,170},
{1,1,1,0,0,0,0,0,0,0,0,0,24,112,145,10,144,197,3,170,227,4,139,193,3,92,143,0,69,136,231,235,241,223,231,237,202,216,224,179,198,212,152,178,196,107,145,170},
{1,1,1,0,0,0,0,0,0,0,0,0,22,109,141,17,143,180,6,172,232,2,145,196,2,89,139,5,74,137,229,234,241,222,230,237,195,214,221,185,201,214,150,176,194,105,143,169},
{0,0,0,0,0,0,0,0,0,3,0,1,22,109,141,18,145,192,3,172,227,0,150,199,0,92,140,22,84,146,231,235,243,219,229,235,197,214,222,181,200,212,149,176,193,101,141,169},
{0,0,0,0,0,0,0,0,0,3,0,1,27,111,142,19,134,175,4,179,230,1,146,197,5,99,151,0,63,128,235,238,241,215,227,232,202,215,225,177,196,210,145,172,192,108,146,172},
{0,0,0,0,0,0,1,1,4,3,3,1,26,103,134,13,150,186,1,176,228,1,146,197,2,93,140,0,66,134,226,237,239,215,226,232,205,218,227,177,197,211,146,174,192,101,142,166},
{0,0,0,0,0,0,0,0,0,31,65,82,29,114,149,14,138,180,1,176,228,3,152,205,5,92,141,0,66,133,229,238,239,217,229,235,203,216,224,182,201,213,146,174,193,92,140,169},
{0,0,0,0,0,0,0,0,0,7,5,12,26,108,133,14,138,180,6,173,223,3,142,197,5,80,130,1,59,119,224,235,240,216,227,234,205,218,226,174,196,208,151,179,197,104,143,165},
{0,0,0,0,0,0,0,0,0,28,79,99,23,117,154,16,146,186,2,183,234,0,142,194,0,98,151,0,66,129,227,235,240,222,230,235,203,216,225,179,198,211,147,174,194,110,146,171},
{0,0,0,0,0,0,0,0,0,13,31,42,28,111,137,18,130,173,4,165,225,4,136,190,4,95,151,15,76,137,229,235,240,221,228,235,207,218,227,174,195,209,149,176,194,104,142,167},
{0,0,0,0,0,0,0,0,0,0,0,1,23,125,152,11,143,186,9,167,218,2,146,198,1,95,148,0,70,136,226,235,241,220,228,235,199,213,222,176,195,208,142,171,189,105,143,168},
{0,0,0,0,0,0,0,0,0,22,59,70,18,117,150,13,136,183,10,177,231,5,133,190,3,95,146,1,70,135,230,237,243,217,227,233,202,218,226,175,196,210,147,175,192,105,144,170},
{0,0,0,0,0,0,0,0,0,11,6,11,21,112,149,19,136,184,2,177,225,5,127,183,7,79,133,0,71,135,228,236,239,219,228,233,200,213,223,179,198,211,145,173,192,94,134,163},
{0,0,0,0,0,0,0,0,0,11,6,11,21,106,135,16,140,180,2,162,220,5,143,196,0,100,145,3,68,138,230,236,238,223,230,236,202,215,224,179,197,211,147,175,194,100,141,168},
{0,0,0,0,0,0,0,0,0,12,44,44,21,96,124,14,130,169,4,169,224,2,145,195,0,94,140,0,70,146,229,234,241,219,229,235,204,217,225,182,199,212,149,177,195,101,139,164},
{0,0,0,0,0,0,0,0,0,12,44,44,17,115,147,13,144,185,1,178,231,1,140,191,2,82,133,27,76,137,231,238,243,220,228,234,201,214,223,176,196,210,138,168,189,96,138,166},
{0,0,0,0,0,0,0,0,0,6,0,0,17,111,135,19,130,172,1,174,223,5,127,184,5,81,131,0,67,131,233,238,243,222,229,236,204,218,226,182,201,214,150,177,194,99,141,169},
{0,0,0,0,0,0,0,0,0,24,73,93,19,105,142,17,146,189,5,174,233,4,142,196,5,77,129,0,71,133,235,239,243,222,230,237,205,219,227,172,193,207,137,168,188,103,143,169},
{0,0,0,0,0,0,0,0,0,12,28,40,19,105,142,14,124,165,3,169,215,1,143,194,3,97,148,54,93,143,233,238,242,223,230,236,198,212,222,181,199,211,148,176,195,99,140,166},
{0,0,0,0,0,0,0,0,0,0,0,1,15,123,150,16,150,188,7,177,231,0,144,194,3,86,137,28,79,134,233,238,242,218,227,233,204,216,226,181,199,213,141,171,191,95,138,167},
{0,0,0,0,0,0,0,0,0,26,70,90,18,97,145,18,131,175,3,173,223,0,136,186,1,89,139,21,75,139,235,237,245,218,227,234,204,217,226,173,193,208,144,172,192,94,135,162},
{0,0,0,0,0,0,0,0,0,15,24,38,20,112,154,13,155,198,1,172,223,1,143,194,1,73,122,0,77,144,229,235,239,218,227,233,201,215,225,177,196,210,145,172,192,103,141,167},
{0,0,0,0,0,0,0,0,0,15,24,38,20,112,154,13,155,198,1,172,223,5,131,186,3,76,122,4,71,140,232,239,243,217,226,233,204,218,227,177,196,209,143,172,192,107,140,162},
{0,0,0,0,0,0,1,2,0,26,74,91,14,120,142,16,128,177,2,169,222,5,125,178,1,89,139,37,80,132,233,237,242,213,225,232,203,217,226,176,196,209,143,171,191,89,133,161},
{0,0,0,0,0,0,1,2,0,2,1,1,13,125,161,11,151,197,4,164,220,1,143,191,1,88,139,58,98,144,233,238,240,212,224,231,201,215,224,180,199,213,142,170,191,100,140,167},
{0,0,0,0,0,0,0,0,0,18,41,52,23,110,153,18,128,165,2,165,216,4,136,187,4,96,146,109,132,164,231,237,242,222,229,236,197,213,222,176,195,209,147,174,193,99,138,168},
{0,0,0,0,0,0,3,0,4,26,82,103,23,110,153,16,156,201,1,176,233,6,134,191,4,80,132,0,63,133,231,239,244,221,230,236,199,213,222,167,190,204,135,166,187,105,140,166},
{0,0,0,0,0,0,2,1,0,10,9,16,20,112,139,20,131,171,2,173,222,2,127,181,5,77,129,34,83,136,232,238,242,222,229,235,202,215,224,179,198,212,147,174,193,93,137,167},
{0,0,0,0,0,0,2,3,2,27,67,83,27,121,152,17,158,195,3,166,220,3,139,191,2,70,116,113,134,171,232,237,241,218,228,235,200,214,223,177,196,210,135,166,185,80,128,159},
{0,0,0,0,0,0,5,0,2,27,67,83,24,106,132,14,136,180,7,164,221,1,137,185,5,77,123,11,72,127,226,232,239,213,223,230,201,215,224,177,197,211,142,171,189,83,131,159},
{0,0,0,0,0,0,1,0,0,18,38,50,24,115,152,15,153,201,5,169,223,5,133,185,2,92,139,91,120,161,233,236,241,221,230,236,199,213,222,174,195,209,142,171,190,86,133,163},
{0,0,0,0,0,0,1,0,0,18,38,50,14,128,167,18,137,178,1,175,223,3,121,173,2,79,129,11,71,130,230,234,241,213,225,231,197,212,221,170,192,206,141,171,192,71,118,150},
{0,0,0,0,0,0,0,0,0,32,86,101,22,123,152,12,159,203,4,171,226,3,136,186,2,82,132,108,136,166,230,237,242,216,227,234,194,211,219,167,191,204,140,169,189,97,141,164},
{0,0,0,0,0,0,0,0,0,12,15,18,19,131,170,14,149,198,2,179,234,1,142,193,5,76,124,29,82,141,229,237,241,220,228,235,192,209,219,172,195,209,134,164,185,94,135,167},
{0,0,0,0,0,0,0,0,1,35,73,94,20,118,151,12,141,186,2,173,225,0,135,185,3,85,131,163,173,192,234,237,242,218,227,233,199,213,222,170,192,207,140,168,189,87,128,158},
{0,0,0,0,0,0,0,0,0,22,96,123,21,129,164,12,161,201,2,168,222,2,140,189,1,83,131,27,83,137,230,236,240,220,227,234,192,208,218,177,197,209,134,165,186,101,141,168},
{0,0,0,0,0,0,0,0,0,24,64,86,23,120,146,16,139,181,0,175,227,5,133,187,3,65,117,1,68,134,232,238,242,214,225,231,199,215,225,172,194,208,140,169,189,82,126,155},
{0,0,0,0,0,0,0,1,1,35,92,117,25,123,164,16,139,181,3,169,223,2,132,187,4,77,127,130,153,184,232,237,242,215,225,231,193,210,219,174,195,209,132,163,184,69,119,153},
{0,0,0,0,0,0,1,1,1,0,1,1,31,112,145,7,150,190,3,169,223,1,134,186,2,85,133,86,119,159,229,237,240,214,224,230,199,213,222,169,191,205,141,170,190,77,126,159},
{0,0,0,0,0,0,0,0,0,26,56,66,19,125,161,11,148,194,2,164,218,1,134,186,0,91,138,49,97,149,226,234,238,212,222,231,201,214,223,173,194,208,132,164,185,93,135,163},
{0,0,0,0,0,0,0,0,0,26,56,66,17,120,157,17,161,207,3,167,221,0,140,189,2,66,115,226,226,233,230,238,241,214,224,232,196,211,220,172,193,207,133,165,185,72,118,151},
{1,1,1,0,0,0,0,0,0,23,45,60,17,120,157,9,143,191,1,177,226,5,130,184,2,73,120,209,210,222,231,238,241,218,227,235,196,211,220,176,197,211,136,168,188,72,119,152},
{1,1,1,0,0,0,0,0,0,23,45,60,21,122,153,13,149,191,1,170,219,4,120,178,1,70,119,184,190,206,232,238,242,219,227,233,196,210,221,168,191,204,139,170,190,81,126,157},
{1,1,1,0,0,0,0,0,0,21,49,64,21,122,153,13,149,191,2,163,216,1,140,190,1,73,122,184,192,210,231,237,241,219,227,233,199,212,223,168,190,204,136,167,187,85,128,156},
{1,1,1,0,0,0,0,0,0,21,49,64,20,129,160,11,154,199,1,165,217,3,138,191,1,76,125,181,191,210,228,235,241,219,227,233,198,212,224,170,191,205,128,161,183,86,128,157},
{1,1,1,0,0,0,0,0,0,21,49,64,30,125,156,9,150,194,3,167,219,3,129,183,2,71,119,182,191,209,233,238,242,219,227,234,198,212,221,168,190,204,139,170,190,84,126,155},
{1,1,1,0,0,0,0,1,2,23,57,65,30,125,156,9,150,194,4,160,215,1,134,187,2,68,115,195,201,217,227,234,238,216,226,232,197,211,220,167,190,204,138,169,189,79,122,149},
{1,1,1,0,1,2,0,1,2,23,57,65,22,130,158,17,155,197,1,166,221,1,135,189,4,70,118,231,230,239,226,233,238,213,224,230,196,210,220,175,195,209,136,167,188,70,118,150},
{0,1,0,0,1,0,0,1,0,29,67,90,22,130,158,11,162,209,0,172,223,1,133,187,4,66,114,244,243,246,228,236,242,217,227,235,196,209,220,173,193,207,134,166,187,75,120,151},
{0,0,0,0,0,0,1,0,0,29,67,90,17,130,165,23,152,186,3,168,222,1,133,182,3,83,131,96,128,163,230,237,242,210,222,229,194,211,221,170,193,207,128,161,184,85,130,159},
{0,0,0,0,0,0,0,1,3,6,7,9,24,119,149,12,155,198,2,163,219,1,133,182,2,80,129,144,160,190,229,236,241,218,228,234,196,213,224,161,187,201,138,168,188,69,118,150},
{0,0,0,0,0,0,1,1,2,27,92,118,20,122,162,13,143,191,2,163,219,6,136,187,1,72,121,198,198,219,232,237,240,218,226,234,195,210,220,165,189,203,130,162,183,86,129,157},
{2,2,2,0,0,0,0,1,0,32,75,92,27,117,152,13,143,191,1,175,224,2,123,176,2,68,116,40,89,140,232,237,239,217,226,233,199,213,222,165,189,204,139,169,190,69,119,152},
{2,2,2,2,2,2,1,0,0,32,91,124,16,134,166,10,161,203,3,164,220,3,128,181,2,81,130,102,129,170,229,235,241,217,228,234,195,210,220,172,194,208,133,164,185,93,135,162},
{2,2,2,2,2,2,3,0,0,27,87,110,23,124,159,17,147,189,2,162,219,4,127,177,0,77,124,238,239,242,224,233,237,217,226,235,200,214,224,167,189,203,137,167,187,74,117,149},
{0,0,0,0,0,0,0,0,0,18,49,62,25,140,170,38,154,191,4,168,224,6,130,183,0,73,118,136,151,181,225,233,237,217,226,235,191,209,219,170,193,206,129,160,182,76,122,154},
{0,0,0,2,2,2,0,0,0,33,101,126,43,130,170,51,190,226,36,186,224,3,124,176,2,79,128,224,225,234,231,237,244,215,225,234,192,211,220,164,187,204,134,165,186,80,127,160},
{0,0,0,2,2,2,0,0,0,32,83,106,42,153,183,50,167,201,75,197,239,3,122,177,1,72,116,121,140,173,229,237,240,217,228,235,192,209,219,169,190,205,131,163,184,98,135,162},
{0,0,0,2,2,2,0,0,0,32,83,106,41,144,174,65,182,221,80,189,225,0,127,180,1,74,124,226,227,237,230,236,242,216,226,232,197,210,219,167,189,203,133,165,186,69,118,146},
{0,0,0,3,3,3,4,5,6,40,102,122,40,138,160,60,184,210,79,191,230,4,126,177,4,64,118,148,160,185,223,233,238,204,219,227,195,211,220,171,193,207,138,169,188,73,117,144},
{0,0,0,0,0,0,21,16,16,40,102,122,52,154,180,74,175,210,90,200,234,97,179,212,2,56,102,243,243,249,224,233,238,212,224,232,197,211,220,170,192,206,126,159,180,81,121,150},
{0,0,0,0,0,0,8,7,7,32,79,87,59,145,173,75,185,218,97,201,230,105,179,209,2,61,112,201,205,220,232,236,242,215,226,234,199,212,223,173,195,208,139,169,190,71,116,148},
{0,0,0,0,0,0,17,22,24,37,117,134,63,160,185,80,175,206,99,203,235,114,189,215,7,63,116,146,164,186,231,239,243,215,227,235,201,213,225,161,185,201,124,157,179,88,132,159},
{0,0,0,0,0,0,0,0,0,45,107,122,63,160,185,84,190,220,106,203,232,123,189,215,0,78,124,252,254,254,226,231,238,220,231,238,191,208,217,171,193,207,138,167,188,72,117,149},
{0,0,0,0,0,0,25,23,21,39,76,83,69,160,181,86,177,202,105,207,236,125,193,218,0,71,121,241,243,251,234,237,241,219,228,235,211,221,231,173,194,208,132,163,184,75,122,149},
{0,0,0,105,105,105,25,23,21,51,123,144,73,160,185,101,205,228,113,207,235,131,188,211,0,62,120,231,236,241,235,238,242,221,229,235,211,221,230,176,194,208,133,165,182,81,123,153},
{0,0,0,105,105,105,6,5,5,55,115,131,75,161,182,92,176,208,118,205,233,131,195,219,2,62,111,60,93,137,234,237,242,221,230,235,213,223,230,196,210,220,134,164,185,84,129,164},
{0,0,0,105,105,105,6,5,5,55,115,131,75,161,182,92,176,208,118,205,233,140,197,220,2,56,102,59,93,137,235,238,243,220,228,234,214,223,231,198,213,220,131,164,184,83,129,163},
{0,0,0,105,105,105,18,16,16,58,133,152,79,167,191,111,199,231,127,208,236,142,197,223,11,77,130,234,238,242,236,239,242,223,230,236,214,225,234,200,213,222,133,161,181,83,123,153},
{0,0,0,108,107,107,18,16,16,56,83,94,87,169,195,101,183,207,127,207,236,144,199,220,18,77,121,244,247,248,231,236,240,219,228,233,210,224,232,202,215,224,135,162,180,76,123,150},
{244,244,244,244,244,244,108,107,107,65,122,136,85,176,193,109,198,221,134,208,231,145,200,220,123,169,198,255,255,255,234,239,242,228,234,240,214,225,231,208,219,228,196,213,224,73,116,148},
{244,244,244,244,244,244,29,34,33,67,138,157,85,176,193,117,189,214,165,228,247,143,202,224,13,71,117,153,164,192,236,241,245,229,234,238,219,227,233,204,217,226,156,182,199,88,132,159},
{255,255,255,255,255,255,127,126,127,66,101,113,96,161,187,142,206,224,184,234,247,151,201,223,0,60,112,209,214,223,235,240,244,229,234,238,220,228,235,211,224,232,200,214,222,71,116,149},
{255,255,255,255,255,255,55,50,50,77,129,151,92,175,195,164,215,234,189,232,244,152,203,222,0,48,96,253,248,252,235,240,244,227,232,236,219,228,235,210,223,231,200,216,227,82,121,150},
{187,187,187,255,255,255,90,94,94,77,129,151,90,162,178,163,218,235,188,231,245,175,213,228,31,82,126,154,164,188,234,239,243,229,234,238,221,230,236,218,227,234,214,223,228,75,116,142},
{187,187,187,253,253,253,254,253,253,71,124,140,98,173,195,173,222,239,197,232,247,211,236,248,109,154,183,228,232,241,235,238,243,231,238,241,222,231,236,219,228,235,217,228,232,69,118,146},
{187,187,187,253,253,253,254,253,253,71,124,140,130,192,214,170,219,234,197,235,247,195,222,238,40,90,133,129,146,173,238,241,246,228,234,238,224,231,237,222,229,234,224,228,232,101,138,164},
{187,187,187,253,253,253,255,255,255,80,142,160,133,194,213,180,231,243,199,234,247,215,238,247,108,146,175,229,229,236,235,242,248,232,238,242,225,231,237,222,229,235,227,232,237,76,128,162},
{251,251,251,251,251,251,255,255,255,72,110,119,149,204,220,173,218,233,197,235,247,214,236,244,20,76,125,145,160,181,235,239,243,232,237,241,227,234,238,226,232,238,236,240,245,75,123,153},
{255,255,255,255,255,255,197,195,194,83,141,155,129,191,209,175,221,236,202,235,245,218,236,245,67,121,158,244,244,248,238,242,248,233,238,242,229,234,238,227,232,238,231,234,238,74,118,148},
{255,255,255,255,255,255,250,251,250,84,153,172,152,200,218,180,227,239,202,238,247,217,238,244,114,159,192,117,136,175,238,242,245,234,238,242,229,234,238,229,234,238,240,240,245,91,136,165},
{255,255,255,249,249,249,250,251,252,87,135,151,140,187,204,181,226,237,202,237,247,218,238,246,16,75,119,50,92,142,239,243,247,233,238,242,231,236,240,231,236,240,236,238,240,71,119,150},
{249,249,249,249,249,249,255,255,255,85,152,170,149,200,217,181,226,237,208,238,248,218,238,246,43,98,141,209,208,223,239,243,247,233,238,242,230,235,239,231,236,240,243,247,248,89,132,158},
{254,254,254,254,254,254,192,192,191,65,71,77,142,188,203,188,227,240,208,238,248,220,238,245,74,122,161,152,169,193,236,241,245,235,240,244,233,238,242,233,238,242,239,242,244,71,118,152},
{254,254,254,254,254,254,253,253,253,81,129,142,146,204,215,182,223,237,208,239,250,220,238,245,111,156,181,103,136,166,239,243,247,233,238,242,233,238,242,234,238,243,251,252,253,85,129,157},
{253,253,254,253,253,254,253,253,254,81,129,142,150,200,220,189,228,242,206,237,248,219,238,245,0,56,106,250,248,250,240,244,247,233,238,242,234,237,242,235,238,243,250,248,247,78,121,151},
{11,11,11,251,252,252,251,252,252,77,114,127,150,200,220,190,230,239,207,239,249,218,238,246,1,66,115,236,236,240,240,244,247,236,239,244,234,237,242,236,239,244,247,247,247,73,119,152},
{11,11,11,253,253,253,251,252,252,77,114,127,149,199,213,188,227,236,212,240,249,218,238,246,6,75,123,206,212,223,240,244,247,236,239,244,234,237,242,237,240,245,242,246,250,79,123,153},
{11,11,11,253,253,253,251,252,249,69,106,113,149,199,213,188,227,236,212,240,249,219,239,248,13,81,129,198,203,218,240,244,247,237,240,244,235,238,243,236,240,244,241,245,246,80,125,159},
{11,11,11,253,253,253,251,252,249,69,106,113,145,203,216,189,230,243,211,239,248,220,239,247,18,85,133,199,203,218,240,244,247,237,241,244,235,238,243,236,240,244,255,255,255,87,130,156},
{11,11,11,253,253,253,251,252,249,69,106,113,148,202,211,188,227,239,211,239,248,219,238,246,18,84,131,198,204,217,240,244,247,237,241,244,235,238,243,237,240,244,244,246,248,84,128,156},
{11,11,11,253,253,253,252,252,250,75,107,122,148,202,211,188,227,239,212,240,249,220,238,245,15,78,124,197,202,212,239,243,246,236,239,244,235,238,243,237,241,245,243,244,246,79,125,154},
{11,11,11,252,252,250,252,252,250,75,107,122,151,200,221,189,227,238,208,240,250,221,237,243,13,71,118,222,220,228,240,244,247,235,238,243,233,238,242,234,240,244,246,246,248,76,121,153},
{253,254,254,253,254,254,253,254,254,82,116,126,151,200,221,191,229,241,207,239,249,220,238,244,2,65,112,238,237,241,240,244,247,236,239,244,234,239,243,234,239,243,247,247,248,77,118,150},
{254,254,254,254,254,254,253,254,255,82,116,126,150,199,216,185,223,238,206,238,248,219,239,244,156,188,211,62,105,151,240,244,247,235,238,243,233,236,241,234,239,243,252,251,252,92,135,161},
{254,254,254,254,254,254,231,231,232,80,83,87,138,189,204,189,228,240,207,239,249,219,239,244,128,167,195,101,129,163,240,244,247,236,241,245,233,238,242,233,238,242,240,242,245,76,125,158},
{252,252,252,252,252,252,255,255,255,89,146,168,145,200,217,182,222,238,207,239,249,218,239,247,91,140,174,150,164,190,240,243,247,233,238,242,232,237,241,233,238,242,243,244,247,73,119,151},
{255,255,255,252,252,252,249,250,249,79,132,145,139,189,204,182,222,238,201,237,246,216,239,246,52,108,145,4,69,136,240,243,249,234,239,243,232,237,241,231,236,240,234,240,241,79,126,157},
{255,255,255,255,255,255,250,252,252,85,152,169,153,201,215,181,226,240,203,236,247,215,239,245,181,210,223,40,89,142,238,241,246,235,238,243,231,236,240,230,235,239,234,239,241,96,139,168},
{255,255,255,255,255,255,252,251,252,89,133,145,134,192,205,170,216,232,204,237,247,215,239,247,133,174,193,176,187,202,238,243,247,234,238,243,231,236,240,229,235,239,230,236,239,87,127,152},
{251,251,251,251,251,251,255,255,255,73,88,92,148,205,223,174,220,236,198,236,248,214,237,244,85,133,163,44,90,142,237,243,248,234,237,242,230,234,238,228,233,237,235,239,242,91,137,168},
{209,209,209,247,247,247,255,255,255,79,142,157,130,195,207,181,226,240,196,236,246,214,236,244,165,196,216,129,147,176,240,243,245,234,237,242,229,234,238,222,229,235,226,231,235,98,140,166},
{209,209,209,247,247,247,254,254,254,72,102,110,133,189,216,170,217,232,200,233,247,214,235,243,128,168,192,16,78,133,238,241,242,234,237,242,225,232,238,222,230,236,221,228,234,69,118,149},
{209,209,209,247,247,247,254,254,254,72,102,110,100,166,190,173,224,240,198,235,247,212,236,245,167,204,218,114,137,168,236,240,242,233,238,241,225,232,238,220,228,234,219,224,230,86,131,164},
{209,209,209,253,253,253,181,182,186,70,123,133,90,159,172,161,211,225,187,234,247,213,236,246,132,170,198,22,76,126,236,240,244,228,235,238,224,231,238,219,228,235,214,225,232,87,128,154},
{255,255,255,255,255,255,47,45,44,70,123,133,98,172,191,165,221,233,184,234,246,207,234,244,49,97,142,133,149,179,238,241,246,229,238,241,223,230,236,217,226,233,218,229,235,75,122,155},
{255,255,255,255,255,255,219,215,216,59,72,77,85,164,183,138,204,219,191,233,246,164,210,230,93,140,170,50,91,138,237,240,246,232,237,241,223,229,235,215,226,232,207,217,226,90,136,166},
{255,255,255,255,255,255,27,32,36,72,131,148,92,168,186,129,206,229,181,235,250,165,214,231,120,165,196,3,66,131,239,240,244,232,237,241,222,229,237,211,221,229,181,201,215,103,140,164},
{255,255,255,255,255,255,206,206,206,64,95,108,92,168,186,104,182,199,164,221,240,144,204,223,164,199,221,125,150,174,236,240,243,232,236,240,218,226,234,209,221,230,204,218,226,96,138,169},
{2,2,2,206,206,206,34,34,34,50,52,54,85,172,190,112,196,227,131,213,236,144,206,228,125,171,202,75,113,150,237,240,245,223,231,237,217,226,233,209,221,229,148,173,191,99,139,167},
{2,2,2,199,199,199,34,34,34,66,120,137,80,162,181,101,185,211,128,214,242,143,202,226,106,159,182,49,89,139,235,239,243,226,233,239,218,227,234,204,215,224,141,168,188,87,130,158},
{2,2,2,199,199,199,17,16,16,49,80,86,83,165,184,101,195,216,120,208,237,139,204,227,2,74,121,0,73,143,235,239,243,225,233,238,217,227,234,205,216,224,141,171,193,106,140,162},
{2,2,2,199,199,199,17,16,16,49,80,86,83,165,184,101,195,216,120,208,237,129,200,224,0,69,119,0,74,146,237,239,244,225,232,237,217,226,233,195,211,222,144,172,192,101,142,167},
{2,2,2,199,199,199,20,21,21,57,110,122,72,152,170,88,184,209,115,207,235,133,191,213,11,89,131,34,78,140,231,238,244,222,231,236,216,225,233,176,196,210,144,171,192,92,132,160},
{2,2,2,0,0,0,20,21,21,37,42,39,75,162,185,95,184,210,106,212,242,129,191,220,0,84,135,42,89,136,235,238,242,221,231,235,208,221,230,177,199,211,139,168,189,98,142,167},
{15,15,15,15,15,15,0,0,0,40,69,71,57,148,176,80,166,197,108,204,235,121,199,218,0,96,144,68,106,152,232,237,241,226,231,237,198,212,222,179,198,210,147,175,195,100,141,166},
{15,15,15,15,15,15,20,20,20,43,102,117,57,148,176,80,184,207,97,203,242,120,198,226,3,85,133,0,69,131,234,238,242,223,230,237,205,218,227,171,193,206,137,167,188,101,142,170},
{15,15,15,15,15,15,9,9,9,29,29,33,55,133,165,71,165,192,99,203,237,90,181,216,1,82,130,1,68,129,232,236,240,221,230,237,203,217,226,181,200,213,150,176,195,99,140,167},
{15,15,15,15,15,15,19,20,20,32,69,78,53,134,165,70,181,210,88,205,235,68,177,217,3,76,124,35,84,134,233,238,244,217,227,233,200,214,222,180,199,213,138,168,189,95,137,165},
{0,0,0,2,2,2,4,4,4,32,69,78,43,122,148,64,164,191,78,202,234,0,140,191,4,87,140,0,68,140,226,234,239,217,228,236,201,215,223,174,197,211,146,175,194,100,139,164},
{0,0,0,0,0,0,1,1,1,16,24,25,45,133,159,64,174,196,87,202,240,2,147,199,1,94,146,9,72,138,232,238,241,223,231,237,201,215,224,177,197,211,145,174,194,100,140,168},
{0,0,0,0,0,0,1,1,1,16,24,25,47,142,169,51,163,199,47,183,230,3,134,186,3,86,137,0,72,134,229,236,242,221,228,234,200,214,224,179,198,210,146,174,193,91,133,162},
{0,0,0,0,0,0,0,0,0,28,74,79,24,131,160,25,148,189,0,180,222,4,136,190,2,97,147,7,71,128,234,238,242,218,226,233,202,216,225,172,194,207,147,174,193,104,144,169},
{1,1,1,1,1,1,0,0,0,3,1,2,20,129,159,13,156,195,7,175,224,4,140,195,3,82,134,0,70,134,234,238,242,219,228,234,201,215,224,181,200,213,140,169,189,104,143,166},
{0,0,0,0,0,0,0,0,0,16,33,46,28,112,135,18,129,168,5,170,227,1,141,193,1,92,141,19,81,135,234,239,243,221,229,237,201,216,225,177,196,210,149,176,195,103,141,166},
{0,0,0,0,0,0,0,0,0,27,81,103,26,117,155,19,145,183,4,184,231,0,149,197,9,96,149,0,66,133,232,237,241,218,227,233,198,212,221,182,200,212,146,174,194,110,146,170},
{0,0,0,2,2,2,0,0,0,8,12,15,23,106,139,16,136,182,7,170,226,1,147,197,2,91,142,2,58,125,230,236,245,220,229,235,205,219,228,180,199,212,152,178,196,104,142,166},
{2,2,2,2,2,2,0,0,0,26,69,86,31,122,147,16,136,182,4,179,228,4,148,200,3,90,142,0,69,131,230,238,241,221,230,236,198,214,223,179,198,212,145,174,193,92,138,168},
{0,0,0,0,0,0,1,0,3,2,5,1,28,99,134,10,145,188,4,179,228,4,135,189,6,100,151,0,64,133,233,237,244,217,228,234,200,215,224,178,198,212,147,176,193,103,144,168},
{0,0,0,0,0,0,0,0,0,3,2,8,28,113,147,16,135,177,5,167,228,4,135,189,1,105,155,0,62,130,230,235,239,220,230,236,200,216,223,178,197,211,144,172,192,107,146,171},
{0,0,0,0,0,0,0,0,0,3,2,8,23,116,148,21,140,191,5,173,229,3,142,194,3,91,141,30,87,151,233,238,244,221,229,234,199,213,222,182,200,214,148,175,195,101,141,167},
{0,0,0,0,0,0,0,0,0,2,0,2,23,116,148,17,141,181,0,180,232,1,142,193,2,86,138,12,76,141,233,239,244,222,230,237,200,214,224,181,199,213,149,176,195,105,143,168},
{0,0,0,0,0,0,0,0,0,2,0,2,34,111,143,9,146,189,3,170,225,2,149,199,3,81,136,0,70,138,232,239,242,223,230,236,203,216,225,178,198,211,148,176,193,106,144,170},
{0,0,0,0,0,0,0,0,0,2,0,2,34,111,143,9,146,189,2,176,228,1,153,203,4,88,142,0,68,137,229,238,241,222,231,237,204,217,226,179,198,211,151,178,195,106,144,170},

};
const int DIVISIONS = sizeof(IMAGE)/sizeof(IMAGE[0]);

#define LED_PIN 9
#define N_CELL 16
const uint8_t INTERRUPT_PIN = 2;
volatile unsigned long crossing_millis = 0;
volatile unsigned long previous_crossing_millis = 0;
uint8_t last_position = 0;
uint8_t curr_position = 0;
const uint8_t BRIGHTNESS = 255;
volatile unsigned long test_val = 0;



class Ledplayer
{
  public:
  Ledplayer()
  {
  }

  void LEDUpdate(NS_Rainbow &ns_stick)
  {
    float ratio = (millis()-crossing_millis) / (float)(crossing_millis-previous_crossing_millis);
    if (ratio > 1)
    {
     ratio = ratio - (int)ratio;
    }
    curr_position = ratio*(DIVISIONS);
    if (curr_position == last_position)
    {
    }
    else
    {
      for(int idx=0; idx<17; idx++)
     {
      uint8_t R = pgm_read_byte(&(IMAGE[curr_position][idx*3]));
      uint8_t G = pgm_read_byte(&(IMAGE[curr_position][idx*3+1]));
      uint8_t B = pgm_read_byte(&(IMAGE[curr_position][idx*3+2]));
        //ns_stick.setColor(idx, IMAGE[curr_position][idx*3],IMAGE[curr_position][idx*3+1],IMAGE[curr_position][idx*3+2]);    
        ns_stick.setColor(idx, R, G, B);
     }

      last_position = curr_position;
      ns_stick.show(); 
    }
  }

  void OnCrossingUpdate()
  {
    previous_crossing_millis = crossing_millis;
    crossing_millis = millis();
  }

};

// Parameter 1 = number of cells (max: 512)
// Parameter 2 = Arduino pin number (default pin: 9)
//NS_Rainbow ns_stick = NS_Rainbow(N_CELL);
NS_Rainbow ns_stick = NS_Rainbow(N_CELL,LED_PIN);
Ledplayer player1 = Ledplayer();

void OnCrossingUpdate()
{
  player1.OnCrossingUpdate();
}


void setup()
{
  ns_stick.begin();
  ns_stick.setBrightness(BRIGHTNESS);  // range: 0 ~ 255, default: 255  
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), OnCrossingUpdate, RISING); 

    //    for(int idx=0; idx<17; idx++)
    // {
    //    ns_stick.setColor(idx, 255,0,0);
    //    ns_stick.show();
    // }

  #if defined(DEVMODE)
    Serial.begin(9600);
  #endif
}

void loop() 
{
  player1.LEDUpdate(ns_stick);
	//delay(100);
}  




