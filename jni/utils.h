#include <jni.h>

# define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))

int registerNativeMethods(JNIEnv* env, const char* className,
		const JNINativeMethod* gMethods, int numMethods);