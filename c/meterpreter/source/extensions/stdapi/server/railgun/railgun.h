#ifndef _METERPRETER_SOURCE_EXTENSION_STDAPI_STDAPI_SERVER_RAILGUN_RAILGUN_H
#define _METERPRETER_SOURCE_EXTENSION_STDAPI_STDAPI_SERVER_RAILGUN_RAILGUN_H


#define TLV_TYPE_EXTENSION_RAILGUN				0

#define TLV_TYPE_RAILGUN_SIZE_OUT				MAKE_CUSTOM_TLV( TLV_META_TYPE_UINT,   TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS +  1 )
#define TLV_TYPE_RAILGUN_STACKBLOB				MAKE_CUSTOM_TLV( TLV_META_TYPE_RAW,    TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS +  2 )
#define TLV_TYPE_RAILGUN_BUFFERBLOB_IN			MAKE_CUSTOM_TLV( TLV_META_TYPE_RAW,    TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS +  3 )
#define TLV_TYPE_RAILGUN_BUFFERBLOB_INOUT		MAKE_CUSTOM_TLV( TLV_META_TYPE_RAW,    TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS +  4 )
#define TLV_TYPE_RAILGUN_BACK_BUFFERBLOB_OUT	MAKE_CUSTOM_TLV( TLV_META_TYPE_RAW,    TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS +  5 )
#define TLV_TYPE_RAILGUN_BACK_BUFFERBLOB_INOUT	MAKE_CUSTOM_TLV( TLV_META_TYPE_RAW,    TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS +  6 )
#define TLV_TYPE_RAILGUN_BACK_RET				MAKE_CUSTOM_TLV( TLV_META_TYPE_QWORD,  TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS +  7 )
#define TLV_TYPE_RAILGUN_BACK_ERR				MAKE_CUSTOM_TLV( TLV_META_TYPE_UINT,   TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS +  8 )
#define TLV_TYPE_RAILGUN_DLLNAME				MAKE_CUSTOM_TLV( TLV_META_TYPE_STRING, TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS +  9 )
#define TLV_TYPE_RAILGUN_FUNCNAME				MAKE_CUSTOM_TLV( TLV_META_TYPE_STRING, TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS + 10 )
#define TLV_TYPE_RAILGUN_MULTI_GROUP			MAKE_CUSTOM_TLV( TLV_META_TYPE_GROUP,  TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS + 11 )
#define TLV_TYPE_RAILGUN_MEM_ADDRESS			MAKE_CUSTOM_TLV( TLV_META_TYPE_QWORD,  TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS + 12 )
#define TLV_TYPE_RAILGUN_MEM_DATA				MAKE_CUSTOM_TLV( TLV_META_TYPE_RAW,    TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS + 13 )
#define TLV_TYPE_RAILGUN_MEM_LENGTH				MAKE_CUSTOM_TLV( TLV_META_TYPE_UINT,   TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS + 14 )
#define TLV_TYPE_RAILGUN_CALLCONV				MAKE_CUSTOM_TLV( TLV_META_TYPE_STRING, TLV_TYPE_EXTENSION_RAILGUN, TLV_EXTENSIONS + 15 )

typedef struct _RAILGUN_INPUT
{
	const char * cpDllName;
	const char * cpFuncName;
	const char * cpCallConv;
	BYTE * pBufferIN;
	BYTE * pBufferINOUT;
	ULONG_PTR dwBufferSizeIN;
	ULONG_PTR dwBufferSizeOUT;
	ULONG_PTR dwBufferSizeINOUT;
	Tlv pStackDescriptorTlv;
} RAILGUN_INPUT;

typedef struct _RAILGUN_OUTPUT
{
	DWORD dwLastError;
	QWORD qwReturnValue;
	BYTE * pBufferOUT;
	BYTE * pBufferINOUT;
	ULONG_PTR dwBufferSizeOUT;
	ULONG_PTR dwBufferSizeINOUT;
} RAILGUN_OUTPUT;

#define p(i)		(ULONG_PTR)pStack[i]
#define function(i)	((STDCALL_FUNC_##i)pFuncAddr)
#define cdecl_func(i)	((CDECL_FUNC_##i)pFuncAddr)

typedef ULONG_PTR (__stdcall * STDCALL_FUNC_00)( VOID );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_01)( ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_02)( ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_03)( ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_04)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_05)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_06)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_07)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_08)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_09)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_10)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_11)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_12)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_13)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_14)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_15)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_16)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_17)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_18)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_19)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_20)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_21)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_22)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_23)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_24)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__stdcall * STDCALL_FUNC_25)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );

typedef ULONG_PTR (__cdecl * CDECL_FUNC_00)( VOID );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_01)( ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_02)( ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_03)( ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_04)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_05)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_06)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_07)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_08)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_09)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_10)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_11)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_12)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_13)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_14)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_15)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_16)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_17)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_18)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_19)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_20)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_21)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_22)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_23)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_24)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );
typedef ULONG_PTR (__cdecl * CDECL_FUNC_25)( ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR, ULONG_PTR );

DWORD request_railgun_api_multi( Remote * remote, Packet * packet );
DWORD request_railgun_api( Remote * pRemote, Packet * pPacket );
DWORD request_railgun_memread( Remote * pRemote, Packet * pPacket );
DWORD request_railgun_memwrite( Remote * pRemote, Packet * pPacket );

#endif

