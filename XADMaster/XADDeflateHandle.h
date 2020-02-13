/*
 * XADDeflateHandle.h
 *
 * Copyright (c) 2017-present, MacPaw Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301  USA
 */
#import "XADLZSSHandle.h"
#import "XADPrefixCode.h"

#define XADNormalDeflateVariant 0
#define XADDeflate64DeflateVariant 1
#define XADStuffItXDeflateVariant 2
#define XADNSISDeflateVariant 3

@interface XADDeflateHandle:XADLZSSHandle
{
	int variant;

	XADPrefixCode *literalcode,*distancecode;
	XADPrefixCode *fixedliteralcode,*fixeddistancecode;
	BOOL storedblock,lastblock;
	int storedcount;

	int order[19];
}

-(id)initWithHandle:(CSHandle *)handle length:(off_t)length;
-(id)initWithHandle:(CSHandle *)handle length:(off_t)length variant:(int)deflatevariant;
-(void)dealloc;

-(void)setMetaTableOrder:(const int *)order;

-(void)resetLZSSHandle;
-(int)nextLiteralOrOffset:(int *)offset andLength:(int *)length atPosition:(off_t)pos;

-(void)readBlockHeader;
-(XADPrefixCode *)allocAndParseMetaCodeOfSize:(int)size;
-(XADPrefixCode *)fixedLiteralCode;
-(XADPrefixCode *)fixedDistanceCode;

@end
