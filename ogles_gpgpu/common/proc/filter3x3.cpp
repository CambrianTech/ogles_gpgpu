//
// ogles_gpgpu project - GPGPU for mobile devices and embedded systems using OpenGL ES 2.0
//
// Author: Markus Konrad <post@mkonrad.net>, Winter 2014/2015
//         David Hirvonen
// http://www.mkonrad.net
//
// See LICENSE file in project repository root for the license.
//

#include "../common_includes.h"
#include "filter3x3.h"

using namespace std;
using namespace ogles_gpgpu;

Filter3x3Proc::Filter3x3Proc()
{

}

void Filter3x3Proc::filterShaderSetup(const char *vShaderSrc, const char *fShaderSrc, GLenum target)
{
    // create shader object
    ProcBase::createShader(vShaderSrc, fShaderSrc, target);
    
    // get shader params
    shParamAPos = shader->getParam(ATTR, "position");
    shParamATexCoord = shader->getParam(ATTR, "inputTextureCoordinate");    
    texelWidthUniform = shader->getParam(UNIF, "texelWidth");
    texelHeightUniform = shader->getParam(UNIF, "texelHeight");
    
    // remember used shader source, required for android issues
    vertexShaderSrcForCompilation = vShaderSrc;
    fragShaderSrcForCompilation = fShaderSrc;
    
    Tools::checkGLErr(getProcName(), "filterShaderSetup");
}

void Filter3x3Proc::getUniforms()
{
    
}

void Filter3x3Proc::setUniforms()
{
    //HACK, broken on android, not getting called at right point, at least in demo
    static bool hasSetUniforms = false;
    if (!hasSetUniforms) {
        hasSetUniforms = true;
        getUniforms();
    }
    
    // Set texel width/height uniforms:
    glUniform1f(texelWidthUniform, (1.0f/ float(outFrameW)));
    glUniform1f(texelHeightUniform, (1.0f/ float(outFrameH)));
}

