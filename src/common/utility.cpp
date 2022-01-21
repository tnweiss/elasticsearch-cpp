//
// Created by tnwei on 1/20/2022.
//

#include "elk/common/utility.h"

#ifdef WIN32

#include "combaseapi.h"

/**
 * Solutions pulled from
 * https://stackoverflow.com/questions/18555306/convert-guid-structure-to-lpcstr
 * and
 * https://stackoverflow.com/questions/24365331/how-can-i-generate-uuid-in-c-without-using-boost-library
 * @return
 */
std::string elk::uuid() {
  // create buffer
  char szGuid[40] = {0};

  // create the GUID
  GUID guid;
  CoCreateGuid(&guid);

  // format the GUID
  sprintf(szGuid, "%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
          guid.Data1, guid.Data2, guid.Data3, guid.Data4[0], guid.Data4[1], guid.Data4[2],
          guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);

  return {szGuid};
}

#else
// linux
#endif