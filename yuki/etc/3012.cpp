//-rdynamic -ldl

#include <stdio.h>
#include <dlfcn.h>
int main(){
	void (*a)() = (void(*)(void))dlsym(RTLD_DEFAULT,"catch");
	a();
}
