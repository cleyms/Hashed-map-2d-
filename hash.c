#include "hash.h"

int mapZtoN(const int x){
	if(x < 0) return -x*2+1;
	return x*2;
}

int mapNNtoN(const int x, const int y){
	return (x+y)*(x+y+1)/2+y;
}

int mapZZtoN(const int x, const int y){
	return mapNNtoN(mapZtoN(x), mapZtoN(y));
}

int hash(const int x, const int y, const int max){
	return mapZZtoN(x, y)%max;
}