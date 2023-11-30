// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2018 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

#include <bits/stdc++.h>
#include <bits/extc++.h>


class ___NAPN {
  //PU
  public:
  std::string s;
  int len;
  void ain() {
    std::cin >> s;
    len = s.size();
  }
  void aout() {
    std::cout << s;
  }
};

bool ___sgn(___NAPN x) {
  return x.s[0] == '-';
}

___NAPN ___to_pstv(___NAPN x) {
  x.len--;
  x.s = x.s.substr(1, x.len);
  return x;
}

___NAPN ___to_ngtv(___NAPN x) {
  x.len++;
  x.s = '-' + x.s;
  return x;
}

___NAPN ___Aabs(___NAPN x) {
  if(x.s[0] == '-') {
    return ___to_pstv(x);
  }
  return x;
}

___NAPN ___ngt(___NAPN x) {
  if(x.s[0] == '-') {
    return ___to_pstv(x);
  }
  return ___to_ngtv(x);
}

void operator +=(___NAPN a, ___NAPN b);

void operator -=(___NAPN a, ___NAPN b) {
  if(___sgn(a) && ___sgn(b)) {
    a = ___ngt(a);
    b = ___ngt(b);
    a += b;
    a = ___ngt(a);
    return ;
  }
  if(___sgn(a)) {
    a = ___ngt(a);
    a += b;
    a = ___ngt(a);
    return ;
  }
  if(___sgn(b)) {
    a += ___ngt(b);
    return ;
  }
}

void operator +=(___NAPN a, ___NAPN b) {
}