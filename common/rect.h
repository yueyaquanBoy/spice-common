/*
   Copyright (C) 2009 Red Hat, Inc.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _H_RECT
#define _H_RECT

#include "draw.h"

#define MIN(x, y) (((x) <= (y)) ? (x) : (y))
#define MAX(x, y) (((x) >= (y)) ? (x) : (y))

static inline void rect_sect(Rect* r, const Rect* bounds)
{
    r->left = MAX(r->left, bounds->left);
    r->right = MIN(r->right, bounds->right);
    r->right = MAX(r->left, r->right);

    r->top = MAX(r->top, bounds->top);
    r->bottom = MIN(r->bottom, bounds->bottom);
    r->bottom = MAX(r->top, r->bottom);
}

static inline void rect_offset(Rect* r, int dx, int dy)
{
    r->left += dx;
    r->right += dx;
    r->top += dy;
    r->bottom += dy;
}

static inline int rect_is_empty(const Rect* r)
{
    return r->top == r->bottom || r->left == r->right;
}

static inline int rect_intersects(const Rect* r1, const Rect* r2)
{
    return r1->left < r2->right && r1->right > r2->left &&
           r1->top < r2->bottom && r1->bottom > r2->top;
}

static inline int rect_is_equal(const Rect *r1, const Rect *r2)
{
    return r1->top == r2->top && r1->left == r2->left &&
           r1->bottom == r2->bottom && r1->right == r2->right;
}

static inline void rect_union(Rect *dest, const Rect *r)
{
    dest->top = MIN(dest->top, r->top);
    dest->left = MIN(dest->left, r->left);
    dest->bottom = MAX(dest->bottom, r->bottom);
    dest->right = MAX(dest->right, r->right);
}

static inline int rect_is_same_size(const Rect *r1, const Rect *r2)
{
    return r1->right - r1->left == r2->right - r2->left &&
           r1->bottom - r1->top == r2->bottom - r2->top;
}

#ifdef __cplusplus

static inline void rect_sect(Rect& r, const Rect& bounds)
{
    rect_sect(&r, &bounds);
}

static inline void rect_offset(Rect& r, int dx, int dy)
{
    rect_offset(&r, dx, dy);
}

static inline int rect_is_empty(const Rect& r)
{
    return rect_is_empty(&r);
}

static inline int rect_intersects(const Rect& r1, const Rect& r2)
{
    return rect_intersects(&r1, &r2);
}

static inline int rect_is_equal(const Rect& r1, const Rect& r2)
{
    return rect_is_equal(&r1, &r2);
}

static inline void rect_union(Rect& dest, const Rect& r)
{
    rect_union(&dest, &r);
}

static inline int rect_is_same_size(const Rect& r1, const Rect& r2)
{
    return rect_is_same_size(&r1, &r2);
}

#endif

#endif

