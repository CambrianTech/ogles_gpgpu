//
// ogles_gpgpu project - GPGPU for mobile devices and embedded systems using OpenGL ES 2.0
//
// Author: Markus Konrad <post@mkonrad.net>, Winter 2014/2015 (http://www.mkonrad.net)
//         David Hirvonen
//
// See LICENSE file in project repository root for the license.
//

/**
 * GPGPU grad processor.
 */
#ifndef OGLES_GPGPU_COMMON_PROC_GRAD
#define OGLES_GPGPU_COMMON_PROC_GRAD

#include "proc/filter3x3.h"

namespace ogles_gpgpu {

/**
 * GPGPU gradient, gradient magnitude and orientation 
 */
class GradProc : public Filter3x3Proc {
public:
    /**
     * Constructor.
     */
    GradProc(float strength=1.f);

    /**
     * Return the processors name.
     */
    virtual const char *getProcName() {
        return "GradProc";
    }

private:
    
    /**
     * Get the fragment shader source.
     */
    virtual const char *getFragmentShaderSource() { return fshaderGradSrc; }
    
    /**
     * Get uniform indices.
     */
    virtual void getUniforms();
    
    /**
     * Set uniform indices.
     */
    virtual void setUniforms();

    static const char *fshaderGradSrc;   // fragment shader source
    
    GLint shParamUStrength;
    
    float strength = 1.f;
};
}

#endif
