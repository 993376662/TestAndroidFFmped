#include <stdlib.h> //NULL 定义在这个文件
#include <jni.h>

//-----------------------jni 工具方法-----------------------
/**
 * 注册一个类中的所有native函数
 */
int registerNativeMethods(JNIEnv* env, const char* className,
		const JNINativeMethod* gMethods, int numMethods) {
	jclass clazz;

	//LOGV("Registering %s natives\n", className);
	clazz = (*env)->FindClass(env, className);
	if (clazz == NULL) {
		//LOGE("Native registration unable to find class '%s'\n", className);
		return -1;
	}
	if ((*env)->RegisterNatives(env, clazz, gMethods, numMethods) < 0) {
		//LOGE("RegisterNatives failed for '%s'\n", className);
		return -1;
	}
	return 0;
}

//\-----------------------jni 工具方法-----------------------