#pragma once
#include <QDebug>

#if DEBUG_MODE
#define TRACE_DBG_FILE_AND_LINE { qDebug ("File:%s:%d [TRACE-DBG]: <%s>",/*
 */__FILE__, __LINE__, "Ok.");}
#else
#define TRACE_DBG_FILE_AND_LINE
#endif /* DEBUG_MODE */
