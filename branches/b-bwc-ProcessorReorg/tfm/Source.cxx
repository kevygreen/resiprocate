#include <iostream>
#include "tfm/Source.hxx"
#include "resip/stack/Tuple.hxx"

Source::Source(const resip::Data& h, int p, resip::TransportType t)
   : host(h), port(p), transportType(t) 
{}

Source::Source()
   : host(), port(0), transportType(resip::UNKNOWN_TRANSPORT) 
{
}


bool 
Source::operator<(const Source& rhs) const
{
   if (host < rhs.host)
   {
      return true;
   }
   else if (host > rhs.host)
   {
      return false;
   }
   else if (transportType < rhs.transportType)
   {
      return true;
   }
   else if (transportType > rhs.transportType)
   {
      return false;
   }
   else
   {
      return port < rhs.port;
   }
}

std::ostream& 
operator<<(std::ostream& os, const Source& src)
{
   os << "Source[" 
      << src.host << ":" << src.port 
      << " " 
      << resip::Tuple::toData(src.transportType) 
      << "]";
   return os;
}
/*
  Copyright (c) 2005, PurpleComm, Inc. 
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  * Neither the name of PurpleComm, Inc. nor the names of its contributors may
    be used to endorse or promote products derived from this software without
    specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
