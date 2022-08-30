#pragma once

#include "header.h"

//  Declare overloaded comparison operators for keys.
  bool operator ==(const Key &x, const Key &y);
  bool operator > (const Key &x, const Key &y);
  bool operator < (const Key &x, const Key &y);
  bool operator >=(const Key &x, const Key &y);
  bool operator <=(const Key &x, const Key &y);
  bool operator !=(const Key &x, const Key &y);