#ifndef __CCEGLVIEWPROTOCOL_H__
#define __CCEGLVIEWPROTOCOL_H__

#include "ccTypes.h"

enum ResolutionPolicy
{
    // The entire application is visible in the specified area without trying to preserve the original aspect ratio.
    // Distortion can occur, and the application may appear stretched or compressed.
    kResolutionExactFit,
    // The entire application fills the specified area, without distortion but possibly with some cropping,
    // while maintaining the original aspect ratio of the application.
    kResolutionNoBorder,
    // The entire application is visible in the specified area without distortion while maintaining the original
    // aspect ratio of the application. Borders can appear on two sides of the application.
    kResolutionShowAll,

    kResolutionUnKnown,
};

NS_CC_BEGIN

#define CC_MAX_TOUCHES  5

class EGLTouchDelegate;
class EGLKeyboardDelegate;
class CCSet;

/**
 * @addtogroup platform
 * @{
 */

class CC_DLL CCEGLViewProtocol
{
public:
    CCEGLViewProtocol();
    virtual ~CCEGLViewProtocol();

    /** Force destroying EGL view, subclass must implement this method. */
    virtual void    end() = 0;

    /** Get whether opengl render system is ready, subclass must implement this method. */
    virtual bool    isOpenGLReady() = 0;

    /** Exchanges the front and back buffers, subclass must implement this method. */
    virtual void    swapBuffers() = 0;

    /** Open or close IME keyboard , subclass must implement this method. */
    virtual void    setIMEKeyboardState(bool bOpen) = 0;

    /**
     * Get the frame size of EGL view.
     * In general, it returns the screen size since the EGL view is a fullscreen view.
     */
    virtual const CCSize& getFrameSize() const;

    /**
     * Set the frame size of EGL view.
     */
    virtual void setFrameSize(float width, float height);

    /**
     * Get the visible area size of opengl viewport.
     */
    virtual CCSize getVisibleSize() const;

    /**
     * Get the visible origin point of opengl viewport.
     */
    virtual CCPoint getVisibleOrigin() const;

    /**
     * Set the design resolution size.
     * @param width Design resolution width.
     * @param height Design resolution height.
     * @param resolutionPolicy The resolution policy desired, you may choose:
     *                         [1] kResolutionExactFit Fill screen by stretch-to-fit: if the design resolution ratio of width to height is different from the screen resolution ratio, your game view will be stretched.
     *                         [2] kResolutionNoBorder Full screen without black border: if the design resolution ratio of width to height is different from the screen resolution ratio, two areas of your game view will be cut.
     *                         [3] kResolutionShowAll  Full screen with black border: if the design resolution ratio of width to height is different from the screen resolution ratio, two black borders will be shown.
     */
    virtual void setDesignResolutionSize(float width, float height, ResolutionPolicy resolutionPolicy);

    /** Get design resolution size.
     *  Default resolution size is the same as 'getFrameSize'.
     */
    virtual const CCSize&  getDesignResolutionSize() const;

    /** Set touch delegate */
    virtual void setTouchDelegate(EGLTouchDelegate * pDelegate);

    /** Set keyboard delegate */
    virtual void setKeyboardDelegate(EGLKeyboardDelegate * pDelegate);

    /**
     * Set opengl view port rectangle with points.
     */
    virtual void setViewPortInPoints(float x , float y , float w , float h);

    /**
     * Set Scissor rectangle with points.
     */
    virtual void setScissorInPoints(float x , float y , float w , float h);

    virtual void setViewName(const char* pszViewName);

    const char* getViewName();

    /** Touch events are handled by default; if you want to customize your handlers, please override these functions: */
    virtual void handleTouchesBegin(int num, int ids[], float xs[], float ys[]);
    virtual void handleTouchesMove(int num, int ids[], float xs[], float ys[]);
    virtual void handleTouchesEnd(int num, int ids[], float xs[], float ys[]);
    virtual void handleTouchesCancel(int num, int ids[], float xs[], float ys[]);

    /** handle keyboard events by default. Note charSequence is typically 1 char */
    virtual void keyUp(unsigned int keyCode, const char* charSequence, unsigned int modifiers, bool shiftKeyPressed, bool controlKeyPressed, bool altKeyPressed, bool commandKeyPressed);
    virtual void keyDown(unsigned int keyCode, const char* charSequence, unsigned int modifiers, bool shiftKeyPressed, bool controlKeyPressed, bool altKeyPressed, bool commandKeyPressed);
    /**
     The flagsChanged: method can be useful for detecting the pressing of modifier keys without any other key being pressed simultaneously. For example, if the user presses the Option key by itself, your responder object can detect this in its implementation of flagsChanged:.
     */
    virtual void flagsChanged(unsigned int keyCode, unsigned int modifiers, bool shiftKeyPressed, bool controlKeyPressed, bool altKeyPressed, bool commandKeyPressed);


    /**
     * Get the opengl view port rectangle.
     */
    const CCRect& getViewPortRect() const;

    /**
     * Get scale factor of the horizontal direction.
     */
    float getScaleX() const;

    /**
     * Get scale factor of the vertical direction.
     */
    float getScaleY() const;
private:
    void getSetOfTouchesEndOrCancel(CCSet& set, int num, int ids[], float xs[], float ys[]);

protected:
    EGLTouchDelegate* m_pDelegate;
    EGLKeyboardDelegate* m_pKeyboardDelegate;

    // real size of screen
    CCSize m_obScreenSize;
    // resolution size, it is the size the app resources designed for
    CCSize m_obDesignResolutionSize;
    // the view port size
    CCRect m_obViewPortRect;
    // the view name
    char   m_szViewName[50];

    float  m_fScaleX;
    float  m_fScaleY;
    ResolutionPolicy m_eResolutionPolicy;
};

// end of platform group
/// @}

NS_CC_END

#endif /* __CCEGLVIEWPROTOCOL_H__ */
