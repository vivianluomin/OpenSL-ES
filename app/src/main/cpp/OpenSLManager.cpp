//
// Created by luomin on 2019-07-24.
//

#include "include/OpenSLManager.h"



void OpenSLManager::createEngine() {

    SLresult sLresult;
    //创建引擎
    sLresult = slCreateEngine(&engineObject, 0, NULL, 0, NULL, NULL);
    //实现engineObject接口对象
    sLresult = (*engineObject)->Realize(engineObject,SL_BOOLEAN_FALSE);
    //初始化engineEngine
    sLresult = (*engineObject)->GetInterface(engineObject,SL_IID_ENGINE,&engineEngine);

}

void OpenSLManager::createMixEngine() {
    SLresult sLresult;
    sLresult = (*engineEngine)->CreateOutputMix(engineEngine,&outputMixObject,1,mid,mreq);
    sLresult = (*outputMixObject)->Realize(outputMixObject,SL_BOOLEAN_FALSE);
    sLresult = (*outputMixObject)->GetInterface(outputMixObject,SL_IID_ENVIRONMENTALREVERB,&outputMixEnvironmenttalReverb);
    if(sLresult == SL_RESULT_SUCCESS){
        sLresult = (*outputMixEnvironmenttalReverb)->SetEnvironmentalReverbProperties(outputMixEnvironmenttalReverb,&reverbSettings);
    }
}

void OpenSLManager::createPlayerEngine(const char *url) {

    //配置audoi source
    SLDataLocator_URI loc_uri = {SL_DATALOCATOR_URI,(SLchar*)url };
    SLDataFormat_MIME format_mime = {SL_DATAFORMAT_MIME,NULL,SL_CONTAINERTYPE_UNSPECIFIED};
    SLDataSource audioSrc = {&loc_uri,&format_mime};

    //配置audio sink
    SLDataLocator_OutputMix loc_outputMix = {SL_DATALOCATOR_OUTPUTMIX,outputMixObject};
    SLDataSink audioSnk = {&loc_outputMix,NULL};

    const SLInterfaceID ids[3] = {SL_IID_SEEK, SL_IID_MUTESOLO, SL_IID_VOLUME};
    const SLboolean req[3] = {SL_BOOLEAN_TRUE, SL_BOOLEAN_TRUE, SL_BOOLEAN_TRUE};


    SLresult  sLresult;
    sLresult = (*engineEngine)->CreateAudioPlayer(engineEngine,&playerObject,&audioSrc,&audioSnk,3,ids,req);
    sLresult = (*playerObject)->Realize(playerObject,SL_BOOLEAN_FALSE);
    sLresult = (*playerObject)->GetInterface(playerObject,SL_IID_PLAY,&playerPlayer);

    if(playerPlayer!=NULL){
        sLresult = (*playerPlayer)->SetPlayState(playerPlayer,SL_PLAYSTATE_PLAYING);
    }
}