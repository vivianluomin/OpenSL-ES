//
// Created by luomin on 2019-07-24.
//

#ifndef OPENSLLEARN_OPENSLMANAGER_H
#define OPENSLLEARN_OPENSLMANAGER_H

extern "C"{
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
};

#include <iostream>
#include <string>



class OpenSLManager{

    const SLInterfaceID mid[1] = {SL_IID_ENVIRONMENTALREVERB};
    const SLboolean  mreq[1] = {SL_BOOLEAN_FALSE};
    const SLEnvironmentalReverbSettings reverbSettings =
            SL_I3DL2_ENVIRONMENT_PRESET_STONECORRIDOR;

private:
    //引擎接口对象
    SLObjectItf engineObject;
    //引擎对象实例
    SLEngineItf engineEngine;
    //混音器接口对象
    SLObjectItf outputMixObject;
    //混音器实例
    SLEnvironmentalReverbItf outputMixEnvironmenttalReverb;
    //播放器接口对象
    SLObjectItf playerObject;
    //播放器实例
    SLPlayItf playerPlayer;

public:
    void createEngine();
    void createMixEngine();
    void createPlayerEngine(const char *url);


};

#endif //OPENSLLEARN_OPENSLMANAGER_H


