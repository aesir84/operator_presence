#pragma once


//
// Qt
//

#include <QtCore\qcoreapplication.h>
#include <QtCore\qobject.h>
#include <QtGui\qevent.h>
#include <QtGui\qimage.h>
#include <QtGui\qopenglbuffer.h>
#include <QtGui\qopenglcontext.h>
#include <QtGui\qopenglfunctions.h>
#include <QtGui\qopenglshaderprogram.h>
#include <QtGui\qopengltexture.h>
#include <QtGui\qopenglvertexarrayobject.h>
#include <QtGui\qscreen.h>
#include <QtGui\qwindow.h>


//
// C++
//

#include <array>
#include <atomic>
#include <cassert>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <vector>


//
// OculusVR
//

#include <OVR_CAPI.h>


//
// OpenCV
//

#include <opencv2\core\mat.hpp>


//
// Helpers
//

#include "scoped_enum_as_integer.h"
