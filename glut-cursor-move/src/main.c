#define PRECOMPILE_HEADERS 0
#define AUTO_RECOMPILE 0

#define SOURCE_PATH "../build/compile-sources.bin"
#define HEADER_PATH "../build/compile-headers.bin"

#include"pch.h"
#include"rcp.h"

#include"app.h"

int main(int argc,char **argv){
	loadGlut(argc,argv);
	createWindow();
	setGlutParameters();
}
