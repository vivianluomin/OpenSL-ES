//
// Created by luomin on 2019-07-24.
//

#include "include/OpenSLManager.h"
#include <jni.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opensllearn_MainActivity_nativePlayMusic(JNIEnv *env,jobject instance,jstring url){

    const char * urll = env->GetStringUTFChars(url,NULL);
    OpenSLManager manager;
    manager.createEngine();
    manager.createMixEngine();
    manager.createPlayerEngine(urll);

}