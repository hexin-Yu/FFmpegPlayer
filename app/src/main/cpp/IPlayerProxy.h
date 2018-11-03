//
// Created by renzhenming on 2018/10/31.
//

#ifndef FFMPEGPLAYER_IPLAYERPROXY_H
#define FFMPEGPLAYER_IPLAYERPROXY_H

#include <mutex>
#include "IPlayer.h"

class IPlayerProxy : public IPlayer {

public:
    static IPlayerProxy *Get() {
        static IPlayerProxy proxy;
        return &proxy;
    }

    void Init(void *vm = 0);

    virtual bool Open(const char *path);

    virtual bool Start();

    virtual void InitView(void *window);

protected:
    IPlayerProxy() {}

    IPlayer *player = 0;

    std::mutex mutex;
};

#endif //FFMPEGPLAYER_IPLAYERPROXY_H