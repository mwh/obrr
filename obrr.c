// obrr - trigger OpenBox to re-read its configuration.
// Copyright (C) 2010 Michael Homer <http://mwh.geek.nz>.
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#include <X11/Xlib.h>

int main(char **argv, int argc) {
    Display *display = XOpenDisplay(NULL);
    Window w = DefaultRootWindow(display);
    XClientMessageEvent e;
    e.type = ClientMessage;
    e.display = display;
    e.window = w;
    e.message_type = XInternAtom(display, "_OB_CONTROL", 0);
    e.format = 32;
    e.data.l[0] = 1;
    e.data.l[1] = 0;
    e.data.l[2] = 0;
    e.data.l[3] = 0;
    e.data.l[4] = 0;
    XSendEvent(display, w, 0,
            SubstructureNotifyMask | SubstructureRedirectMask,
            (XEvent*)&e);
    XFlush(display);
    return 0;
}
/* vim: set expandtab ts=8 sw=4 tw=72: */
