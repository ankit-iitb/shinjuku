#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>
#include <ix/log.h>

void call_extension() {
	uint8_t (*fptr)(uint8_t, uint8_t);
	void *handle = dlopen("/users/ankitb/shinjuku/dp/core/libawesome_math.so", RTLD_LAZY);
	if (!handle) {
        	log_err("Cannot open library: %s\n", dlerror());
        	return;
    	}
	fptr = dlsym(handle, "from_the_library");
	uint8_t result = (*fptr)(1,2);
	printf("result %d\n", result);
	dlclose(handle);
}
