/****************************************************************************
Copyright (c) 2021      Yinbaiyuan

https://www.yinbaiyuan.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __Text_H__
#define __Text_H__

#include "Dot2D/dot2d.h"

NS_DT_BEGIN

class TextLayer;

class Text : public Scene
{

protected:
    bool init() override;

public:
    STATIC_CREATE(Text);
};

class TextLayer : public Layer
{
public:
    virtual ~TextLayer();

protected:
    CanvasSprite *m_str_sprite = nullptr;

public:
    STATIC_CREATE(TextLayer);

    virtual bool initLayer();

    void draw_cmd(void);

    void update(float dt) override;

    static int32_t screen_H;
    static int32_t screen_W;
    static int32_t screen_char_num;
};

NS_DT_END

#endif //__Text_H__