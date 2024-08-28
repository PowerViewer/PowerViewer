/**
 * @file llfontgl.h
 * @author Andrii Kleshchev
 * @brief Buffer storage for font rendering.
 *
 * $LicenseInfo:firstyear=2001&license=viewerlgpl$
 * Second Life Viewer Source Code
 * Copyright (C) 2010, Linden Research, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License only.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Linden Research, Inc., 945 Battery Street, San Francisco, CA  94111  USA
 * $/LicenseInfo$
 */

#ifndef LL_LLFONTVERTEXBUFFER_H
#define LL_LLFONTVERTEXBUFFER_H

#include "llfontgl.h"

class LLVertexBuffer;

class LLFontVertexBuffer
{
public:
    LLFontVertexBuffer(bool track_changes = true);
    ~LLFontVertexBuffer();

    void reset();

    S32 render(const LLFontGL* fontp,
        const LLWString& text,
        S32 begin_offset,
        F32 x, F32 y,
        const LLColor4& color,
        LLFontGL::HAlign halign = LLFontGL::LEFT, LLFontGL::VAlign valign = LLFontGL::BASELINE,
        U8 style = LLFontGL::NORMAL, LLFontGL::ShadowType shadow = LLFontGL::NO_SHADOW,
        S32 max_chars = S32_MAX, S32 max_pixels = S32_MAX,
        F32* right_x = NULL,
        bool use_ellipses = false,
        bool use_color = true);

private:

    void genBuffers(const LLFontGL* fontp,
         const LLWString& text,
         S32 begin_offset,
         F32 x, F32 y,
         const LLColor4& color,
         LLFontGL::HAlign halign, LLFontGL::VAlign valign,
         U8 style, LLFontGL::ShadowType shadow,
         S32 max_chars, S32 max_pixels,
         F32* right_x,
         bool use_ellipses,
         bool use_color);


    std::list<LLFontGL::LLVertexBufferData> mBufferList;
    S32 mChars = 0;
    S32 mLastOffset = 0;
    S32 mLastMaxChars = 0;
    S32 mLastMaxPixels = 0;
    size_t mLastStringHash = 0;
    F32 mLastX = 0.f;
    F32 mLastY = 0.f;
    LLColor4 mLastColor;
    F32 mLastRightX = 0.f;
    bool mTrackStringChanges = true;

    static std::hash<LLWString> sStringHasher;
};

#endif