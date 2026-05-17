#define TRUSSC_SHOW_CONSOLE 1
#include "TrussC.h"
#include "tcxHapPlayer.h"

#include "tcxHapJl.h"

#include "jlcxx/jlcxx.hpp"
#include "jlcxx/stl.hpp"

// // NOTE: This line comment is left for future usage
// #include "trussc_generated.h"

using namespace std;
using namespace tc;


namespace jlcxx
{
//   template<> struct IsMirroredType<FpsSettings> : std::false_type { };
}

JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{

    // // NOTE: this comment is left for reference.

    //   mod.method("greet", &greet);
    //   mod.method("runTrusscTestApp", [](){ runTrusscTestApp(); });

    //   mod.add_type<Vec2>("Vec2")
    //     .constructor<>()
    //     .constructor<float, float>()
    //     .constructor<const Vec2&>()
    //     .method("x", [](Vec2& v){ return v.x; })

    //   mod.add_enum<PrimitiveMode>("PrimitiveMode",
    //         std::vector<const char*>({
    //             "Triangles",
    //         }),
    //         std::vector<int>({
    //             (int)PrimitiveMode::Triangles,
    //         })
    //     );

    // // End of references.

    using HapFormat = tcx::hap::HapFormat;
    using HapPlayer = tcx::hap::HapPlayer;

    mod.add_enum<HapFormat>("HapFormat",
        std::vector<const char*>({
            "Unknown",
            "DXT1",
            "DXT5",
            "YCoCgDXT5",
            "BC7",
            "RGTC1"
        }),
        std::vector<int>({
            (int)HapFormat::Unknown,
            (int)HapFormat::DXT1,
            (int)HapFormat::DXT5,
            (int)HapFormat::YCoCgDXT5,
            (int)HapFormat::BC7,
            (int)HapFormat::RGTC1
        })
    );

    mod.add_type<HapPlayer>("HapPlayer")
        .constructor<>()
        // FIXME: move constructor?
        .method("getDecodeTimeMs", &HapPlayer::getDecodeTimeMs)
        .method("getChunkCount", &HapPlayer::getChunkCount)
        .method("resetStats", &HapPlayer::resetStats)
        .method("getHapFormat", &HapPlayer::getHapFormat)
        // .method("setSpeed", &HapPlayer::setSpeed)
        // .method("isHapFile", &HapPlayer::isHapFile)
        .method("load", &HapPlayer::load)
        .method("close", &HapPlayer::close)
        .method("isLoaded", &HapPlayer::isLoaded)
        .method("play", &HapPlayer::play)
        .method("stop", &HapPlayer::stop)
        .method("setPaused", &HapPlayer::setPaused)
        .method("togglePause", &HapPlayer::togglePause)
        .method("update", &HapPlayer::update)
        .method("isPlaying", &HapPlayer::isPlaying)
        .method("isPaused", &HapPlayer::isPaused)
        .method("isFrameNew", &HapPlayer::isFrameNew)
        .method("isDone", &HapPlayer::isDone)
        .method("getWidth", &HapPlayer::getWidth)
        .method("getHeight", &HapPlayer::getHeight)
        .method("getDuration", &HapPlayer::getDuration)
        .method("getPosition", &HapPlayer::getPosition)
        .method("setPosition", &HapPlayer::setPosition)
        .method("getCurrentTime", &HapPlayer::getCurrentTime)
        .method("setCurrentTime", &HapPlayer::setCurrentTime)
        .method("getVolume", &HapPlayer::getVolume)
        .method("setVolume", &HapPlayer::setVolume)
        .method("getSpeed", &HapPlayer::getSpeed)
        .method("setSpeed", &HapPlayer::setSpeed)
        .method("setPan", &HapPlayer::setPan)
        .method("getPan", &HapPlayer::getPan)
        .method("setLoop", &HapPlayer::setLoop)
        .method("isLoop", &HapPlayer::isLoop)
        .method("getCurrentFrame", &HapPlayer::getCurrentFrame)
        .method("getTotalFrames", &HapPlayer::getTotalFrames)
        .method("setFrame", &HapPlayer::setFrame)
        .method("nextFrame", &HapPlayer::nextFrame)
        .method("previousFrame", &HapPlayer::previousFrame)
        .method("getPixels", [](HapPlayer& p){ return p.getPixels(); })
        .method("hasAudio", &HapPlayer::hasAudio)
        .method("getAudioCodec", &HapPlayer::getAudioCodec)
        .method("getAudioData", &HapPlayer::getAudioData)
        .method("getAudioSampleRate", &HapPlayer::getAudioSampleRate)
        .method("getAudioChannels", &HapPlayer::getAudioChannels)
        .method("isUsingHwAccel", &HapPlayer::isUsingHwAccel)
        .method("getHwAccelName", &HapPlayer::getHwAccelName)
        .method("setResyncThreshold", &HapPlayer::setResyncThreshold)
        .method("getResyncThreshold", &HapPlayer::getResyncThreshold)
        // .method("getTexture", &HapPlayer::getTexture)
        // WORKAROUND
        .method("getTexturePtr", [](HapPlayer& p){ 
            Texture& tex = p.getTexture();
            return (void*) &tex;
        })
        ;

    mod.method("HapPlayer_isHapFile", &HapPlayer::isHapFile);

    // //  NOTE: This line comment is left for future usage
    //   define_julia_module_trussc_generated(mod);
}
