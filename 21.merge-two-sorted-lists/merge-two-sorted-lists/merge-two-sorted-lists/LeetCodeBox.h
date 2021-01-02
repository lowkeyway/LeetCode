#ifndef _LEETCODE_BOX_
#define _LEETCODE_BOX_


#define ARRAY_SIZE(X)	sizeof(X) / sizeof(X[0])

#define ABS(X)          (X) > 0 ? (X) : (-X)
#define MIN(a, b)       (a) < (b) ? (a) : (b)
#define MAX(a, b)       (a) > (b) ? (a) : (b)
#define ABS_MIN(a, b)   (ABS(a)) < (ABS(b)) ? (a) : (b)
#define ABS_MAX(a, b)   (ABS(a)) > (ABS(b)) ? (a) : (b)

#define TRUE			1
#define FALSE			0

typedef unsigned int	uint;
typedef unsigned char	uchar;
typedef unsigned long	ulong;

#endif // !_LEETCODE_BOX_
#pragma once
