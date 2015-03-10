#ifndef _XRDSSIRRINFO_H
#define _XRDSSIRRINFO_H
/******************************************************************************/
/*                                                                            */
/*                       X r d S s i R R I n f o . h h                        */
/*                                                                            */
/* (c) 2013 by the Board of Trustees of the Leland Stanford, Jr., University  */
/*                            All Rights Reserved                             */
/*   Produced by Andrew Hanushevsky for Stanford University under contract    */
/*              DE-AC02-76-SFO0515 with the Department of Energy              */
/*                                                                            */
/* This file is part of the XRootD software suite.                            */
/*                                                                            */
/* XRootD is free software: you can redistribute it and/or modify it under    */
/* the terms of the GNU Lesser General Public License as published by the     */
/* Free Software Foundation, either version 3 of the License, or (at your     */
/* option) any later version.                                                 */
/*                                                                            */
/* XRootD is distributed in the hope that it will be useful, but WITHOUT      */
/* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or      */
/* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public       */
/* License for more details.                                                  */
/*                                                                            */
/* You should have received a copy of the GNU Lesser General Public License   */
/* along with XRootD in a file called COPYING.LESSER (LGPL license) and file  */
/* COPYING (GPL license).  If not, see <http://www.gnu.org/licenses/>.        */
/*                                                                            */
/* The copyright holder's institutional names and contributor's names may not */
/* be used to endorse or promote products derived from this software without  */
/* specific prior written permission of the institution or contributor.       */
/******************************************************************************/

#include "XrdSys/XrdSysPlatform.hh"

struct XrdSsiRRInfo
{
char               Cmd;
char               Rsv[2];
char               Id;
int                Size;

inline unsigned long long Info()
       {return (static_cast<unsigned long long>(Cmd)<<56LL)
              |(static_cast<unsigned long long>(Id )<<32LL) | Size;}

static const char  Rxq = 0;
static const char  Rwt = 1;
static const char  Can = 2;

       XrdSsiRRInfo(unsigned long long ival=0) : Cmd(ival>>56), Id(ival>>32),
                                                Size(ival & 0xffffffff) {}
      ~XrdSsiRRInfo() {}
};
#endif
