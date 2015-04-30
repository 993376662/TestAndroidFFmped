#include <stdio.h>
#include <assert.h>
#include "utils.h"

jint avcodec_find_decoder(JNIEnv* env, jint thiz) {
	return thiz;
}

/**
 * 方法对应表
 */
static JNINativeMethod gMethods_a[] = { { "avcodec_find_decoder", "(I)I;",
		(void*) avcodec_find_decoder }, //绑定
		};

int register_avcodec_find_decoder(JNIEnv *env) {
	return registerNativeMethods(env, "cn/dennishucd/FFmpegNative", gMethods_a,
			NELEM(gMethods_a));
}

//调用完System.loadLibrary方法后,如果该方法存在就会被调用,所有jni动态注册在这里完成
jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	JNIEnv* env = NULL;
	jint result = -1;

	if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		//LOGE("ERROR: GetEnv failed\n");
		goto bail;
	}
	assert(env != NULL);

	if (register_avcodec_find_decoder(env) < 0) {
		//LOGE("ERROR: Hello native registration failed\n");
		goto bail;
	}

	/* success -- return valid version number */
	result = JNI_VERSION_1_4;

	bail: return result;
}

