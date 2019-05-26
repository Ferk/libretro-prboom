// Copyright (c) 2010, Braden "Blzut3" Obrzut <admin@maniacsvault.net>
// Copyright (c) 2019, Fernando Carmona Varo  <ferkiwi@gmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//    * Neither the name of the <organization> nor the
//      names of its contributors may be used to endorse or promote products
//      derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef __UF_SCANNER_H__
#define __UF_SCANNER_H__

#include "doomtype.h"

enum
{
  TK_Identifier,  // Ex: SomeIdentifier
  TK_StringConst,  // Ex: "Some String"
  TK_IntConst,  // Ex: 27
  TK_FloatConst,  // Ex: 1.5
  TK_BoolConst,  // Ex: true
  TK_AndAnd,    // &&
  TK_OrOr,    // ||
  TK_EqEq,    // ==
  TK_NotEq,    // !=
  TK_GtrEq,    // >=
  TK_LessEq,    // <=
  TK_ShiftLeft,  // <<
  TK_ShiftRight,  // >>

  TK_NumSpecialTokens,

  TK_NoToken = -1
};

typedef struct
{
  char          *string;
  int            number;
  double        decimal;
  boolean        boolean;
  char          token;
  unsigned int  tokenLine;
  unsigned int  tokenLinePosition;
} uf_parserstate_t;

typedef struct
{
  uf_parserstate_t  nextState;

  char*            data;
  unsigned int     length;

  unsigned int     line;
  unsigned int     lineStart;
  unsigned int     logicalPosition;
  unsigned int     tokenLine;
  unsigned int     tokenLinePosition;
  unsigned int     scanPos;

  boolean          needNext; // If checkToken returns false this will be false.

  char*   string;
  int     number;
  double  decimal;
  boolean boolean;
  char    token;

} uf_scanner_t;


uf_scanner_t UF_Create(const byte* data, int length);
void         UF_Destroy(uf_scanner_t* scanner);
boolean      UF_GetNextToken(uf_scanner_t* scanner, boolean expandState);
boolean      UF_HasTokensLeft(uf_scanner_t* scanner);
void         UF_MustGetToken(uf_scanner_t* scanner, char token);
void         UF_MustGetIdentifier(uf_scanner_t* scanner, const char *ident);
void         UF_MustGetInteger(uf_scanner_t* s);
void         UF_MustGetFloat(uf_scanner_t* s);
boolean      UF_CheckToken(uf_scanner_t* scanner, char token);
boolean      UF_CheckInteger(uf_scanner_t* s);
boolean      UF_CheckFloat(uf_scanner_t* s);
void         UF_SetString(char **ptr, const char *start, int length);
void         UF_ReplaceString(char **ptr, const char *newstring);

void         UF_Error(uf_scanner_t* s, const char *msg, ...);
void         UF_ErrorToken(uf_scanner_t* s, int token);
void         UF_ErrorString(uf_scanner_t* s, const char *mustget);

#endif /* __UF_SCANNER_H__ */
