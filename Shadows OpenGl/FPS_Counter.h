//
//  FPS_Counter.h
//  Shadows OpenGl
//
//  Created by Githinji Wanjohi on 9/19/18.
//  Copyright © 2018 Githinji Wanjohi. All rights reserved.
//

#define KGLLIB_FPSCOUNTER_H


#include <QtCore/QTime>
#include <QtCore/QString>


/**
 * @brief Utility class that measures FPS.
 *
 * FPSCounter is a utility class that keeps track of FPS (frames per second) of
 *  your application. It can be a simple performance measurement tool.
 *
 * Using FPSCounter is simple: if you're using GLWidget then all you have to do
 *  is calling fps() or fpsString() method to find out the current FPS. You can
 *  also call timeElapsed() to find out how much time has elapsed since last
 *  frame was rendered. This could be useful e.g. in animations where an object
 *  has a fixed speed and you multiply it by the elapsed time every frame to
 *  find out how much the object should be moved.
 *
 * If you don't use GLWidget then you need to call nextFrame() every time that
 *  another frame is rendered.
 *
 * The fps value is recalculated once a second.
 *
 * You can also use totalTimeElapsed() to find out how much time has elapsed
 *  since nextFrame() was called the very first time.
 *
 * @see GLWidget
 **/
class FPSCounter
{
public:
    /**
     * Creates new FPS counter. The counter isn't started until nextFrame()
     *  is called for the first time.
     **/
    FPSCounter();
    
    /**
     * This method should be called whenever a frame is rendered. It increases
     *  the internal counters and updates the calculated FPS value once a
     *  second.
     *
     * @see fps(), timeElapsed()
     **/
    void nextFrame();
    void resetTimeElapsed();
    
    /**
     * Returns the current FPS value.
     *
     * Note that the value is recalculated by nextFrame() about once a second.
     *
     * @see fpsString(), timeElapsed(), nextFrame()
     **/
    float fps() const  { return mFPS; }
    /**
     * Returns the current FPS value as string.
     *
     * Number of significant digits in the string is kept at 3, so possible
     *  return values include "123", "42.7" and "3.84".
     *
     * @see fps()
     **/
    QString fpsString() const;
    /**
     * Returnes time elapsed between last two calls to nextFrame() method.
     * Usually that gives you the time elapsed since last frame and could be
     *  used e.g. for animation purposes.
     *
     * The return value is in seconds, thus a value of 0.075 would indicate
     *  that 75 milliseconds have elapsed.
     *
     * @see fps()
     **/
    // TODO: rename to timeSinceLastFrame()? change semantics?
    float timeElapsed() { return mTimeElapsed; }
    /**
     * Returns amount of time that has elapsed since the first call to
     *  nextFrame().
     *
     * @see timeElapsed(), nextFrame()
     **/
    float totalTimeElapsed()  { return mTotalTimeElapsed; }
    
protected:
    QTime mTime;
    int mFrames;
    float mFPS;
    
    float mTimeElapsed;  // in sec
    float mTotalTimeElapsed;  // in sec
    QTime mLastTime;
};



#endif
