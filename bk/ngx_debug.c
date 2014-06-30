#include <ngx_debug.h>

static FILE *fp;

void main_constructor( void ) {
	fp = fopen( "/tmp/trace.txt", "w" );
	if (fp == NULL) exit(-1);
}

void main_deconstructor( void ) {
	fclose( fp );
}

void __attribute__((__no_instrument_function__)) __cyg_profile_func_enter(void *this_func, void *call_site) {
	DUMP(this_func, call_site);
}

void __attribute__((__no_instrument_function__)) __cyg_profile_func_exit(void *this_func, void *call_site) {
	DUMP(this_func, call_site);
}
