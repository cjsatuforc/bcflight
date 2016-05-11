#ifndef STREAM_H
#define STREAM_H

#include <vc_dispmanx_types.h>
#include <bcm_host.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>

#include <gammaengine/Instance.h>
#include <gammaengine/Window.h>
#include <gammaengine/Thread.h>
#include <gammaengine/Timer.h>
#include <gammaengine/Socket.h>
#include <gammaengine/Renderer2D.h>
#include <gammaengine/Font.h>

#include <Thread.h>
#include "decode.h"
#include "DecodedImage.h"
#include "RendererHUD.h"

// #include <wifibroadcast.h>

using namespace GE;

class Controller;

class Stream : GE::Thread
{
public:
	Stream( Controller* controller, Font* font, const std::string& addr, uint16_t port = 2021 );
	~Stream();

	int linkLevel() const { return mIwStats.level; }
	int linkQuality() const { return mIwStats.qual; }

	EGL_DISPMANX_WINDOW_T CreateNativeWindow( int layer );

protected:
	virtual bool run();
	bool DecodeThreadRun();
	bool SignalThreadRun();

private:
	Instance* mInstance;
	Window* mWindow;
	Controller* mController;
	Font* mFont;
	Timer mSecondTimer;
	RendererHUD* mRendererHUD;

// 	rwifi_rx_t* mRx;
	Socket* mSocket;
	std::string mSockerAddr;
	uint16_t mSocketPort;
	HookThread<Stream>* mDecodeThread;
	void* mDecodeInput;

	int mIwSocket;
	IwStats mIwStats;
	HookThread<Stream>* mSignalThread;

	Timer mFPSTimer;
	int mFPS;
	int mFrameCounter;
	int mBitrateCounter;

	EGL_DISPMANX_WINDOW_T mLayerDisplay;
	EGLImageKHR mEGLVideoImage;
	GLuint mVideoTexture;
	video_context* mDecodeContext;

	DISPMANX_DISPLAY_HANDLE_T mDisplay;
	struct {
		DISPMANX_RESOURCE_HANDLE_T resource;
		VC_RECT_T rect;
		void *image;
		uint32_t vc_image_ptr;
	} mScreenshot;
};

#endif // STREAM_H
