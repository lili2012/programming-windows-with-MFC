

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sat Jul 14 20:18:48 2018
 */
/* Compiler settings for AutoPie.odl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __AutoPie_h_h__
#define __AutoPie_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAutoPie_FWD_DEFINED__
#define __IAutoPie_FWD_DEFINED__
typedef interface IAutoPie IAutoPie;

#endif 	/* __IAutoPie_FWD_DEFINED__ */


#ifndef __Application_FWD_DEFINED__
#define __Application_FWD_DEFINED__

#ifdef __cplusplus
typedef class Application Application;
#else
typedef struct Application Application;
#endif /* __cplusplus */

#endif 	/* __Application_FWD_DEFINED__ */


#ifndef __IAutoChart_FWD_DEFINED__
#define __IAutoChart_FWD_DEFINED__
typedef interface IAutoChart IAutoChart;

#endif 	/* __IAutoChart_FWD_DEFINED__ */


#ifndef __AutoChart_FWD_DEFINED__
#define __AutoChart_FWD_DEFINED__

#ifdef __cplusplus
typedef class AutoChart AutoChart;
#else
typedef struct AutoChart AutoChart;
#endif /* __cplusplus */

#endif 	/* __AutoChart_FWD_DEFINED__ */


#ifndef __IAutoWindow_FWD_DEFINED__
#define __IAutoWindow_FWD_DEFINED__
typedef interface IAutoWindow IAutoWindow;

#endif 	/* __IAutoWindow_FWD_DEFINED__ */


#ifndef __AutoWindow_FWD_DEFINED__
#define __AutoWindow_FWD_DEFINED__

#ifdef __cplusplus
typedef class AutoWindow AutoWindow;
#else
typedef struct AutoWindow AutoWindow;
#endif /* __cplusplus */

#endif 	/* __AutoWindow_FWD_DEFINED__ */


#ifndef __IAutoToolbar_FWD_DEFINED__
#define __IAutoToolbar_FWD_DEFINED__
typedef interface IAutoToolbar IAutoToolbar;

#endif 	/* __IAutoToolbar_FWD_DEFINED__ */


#ifndef __AutoToolbar_FWD_DEFINED__
#define __AutoToolbar_FWD_DEFINED__

#ifdef __cplusplus
typedef class AutoToolbar AutoToolbar;
#else
typedef struct AutoToolbar AutoToolbar;
#endif /* __cplusplus */

#endif 	/* __AutoToolbar_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __AutoPie_LIBRARY_DEFINED__
#define __AutoPie_LIBRARY_DEFINED__

/* library AutoPie */
/* [version][uuid] */ 


DEFINE_GUID(LIBID_AutoPie,0x3B5BA307,0x3B72,0x11D2,0xAC,0x82,0x00,0x60,0x08,0xA8,0x27,0x4D);

#ifndef __IAutoPie_DISPINTERFACE_DEFINED__
#define __IAutoPie_DISPINTERFACE_DEFINED__

/* dispinterface IAutoPie */
/* [uuid] */ 


DEFINE_GUID(DIID_IAutoPie,0x3B5BA308,0x3B72,0x11D2,0xAC,0x82,0x00,0x60,0x08,0xA8,0x27,0x4D);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3B5BA308-3B72-11D2-AC82-006008A8274D")
    IAutoPie : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IAutoPieVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoPie * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoPie * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoPie * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoPie * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoPie * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoPie * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoPie * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IAutoPieVtbl;

    interface IAutoPie
    {
        CONST_VTBL struct IAutoPieVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoPie_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoPie_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoPie_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoPie_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoPie_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoPie_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoPie_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IAutoPie_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_Application,0x3B5BA306,0x3B72,0x11D2,0xAC,0x82,0x00,0x60,0x08,0xA8,0x27,0x4D);

#ifdef __cplusplus

class DECLSPEC_UUID("3B5BA306-3B72-11D2-AC82-006008A8274D")
Application;
#endif

#ifndef __IAutoChart_DISPINTERFACE_DEFINED__
#define __IAutoChart_DISPINTERFACE_DEFINED__

/* dispinterface IAutoChart */
/* [uuid] */ 


DEFINE_GUID(DIID_IAutoChart,0x3B5BA31D,0x3B72,0x11D2,0xAC,0x82,0x00,0x60,0x08,0xA8,0x27,0x4D);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3B5BA31D-3B72-11D2-AC82-006008A8274D")
    IAutoChart : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IAutoChartVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoChart * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoChart * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoChart * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoChart * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoChart * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoChart * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoChart * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IAutoChartVtbl;

    interface IAutoChart
    {
        CONST_VTBL struct IAutoChartVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoChart_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoChart_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoChart_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoChart_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoChart_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoChart_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoChart_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IAutoChart_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_AutoChart,0x3B5BA31F,0x3B72,0x11D2,0xAC,0x82,0x00,0x60,0x08,0xA8,0x27,0x4D);

#ifdef __cplusplus

class DECLSPEC_UUID("3B5BA31F-3B72-11D2-AC82-006008A8274D")
AutoChart;
#endif

#ifndef __IAutoWindow_DISPINTERFACE_DEFINED__
#define __IAutoWindow_DISPINTERFACE_DEFINED__

/* dispinterface IAutoWindow */
/* [uuid] */ 


DEFINE_GUID(DIID_IAutoWindow,0x3B5BA320,0x3B72,0x11D2,0xAC,0x82,0x00,0x60,0x08,0xA8,0x27,0x4D);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3B5BA320-3B72-11D2-AC82-006008A8274D")
    IAutoWindow : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IAutoWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoWindow * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoWindow * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoWindow * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoWindow * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoWindow * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoWindow * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoWindow * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IAutoWindowVtbl;

    interface IAutoWindow
    {
        CONST_VTBL struct IAutoWindowVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoWindow_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoWindow_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoWindow_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoWindow_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoWindow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoWindow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoWindow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IAutoWindow_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_AutoWindow,0x3B5BA322,0x3B72,0x11D2,0xAC,0x82,0x00,0x60,0x08,0xA8,0x27,0x4D);

#ifdef __cplusplus

class DECLSPEC_UUID("3B5BA322-3B72-11D2-AC82-006008A8274D")
AutoWindow;
#endif

#ifndef __IAutoToolbar_DISPINTERFACE_DEFINED__
#define __IAutoToolbar_DISPINTERFACE_DEFINED__

/* dispinterface IAutoToolbar */
/* [uuid] */ 


DEFINE_GUID(DIID_IAutoToolbar,0x3B5BA323,0x3B72,0x11D2,0xAC,0x82,0x00,0x60,0x08,0xA8,0x27,0x4D);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3B5BA323-3B72-11D2-AC82-006008A8274D")
    IAutoToolbar : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IAutoToolbarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoToolbar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoToolbar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoToolbar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoToolbar * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoToolbar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoToolbar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoToolbar * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IAutoToolbarVtbl;

    interface IAutoToolbar
    {
        CONST_VTBL struct IAutoToolbarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoToolbar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoToolbar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoToolbar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoToolbar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoToolbar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoToolbar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoToolbar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IAutoToolbar_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_AutoToolbar,0x3B5BA325,0x3B72,0x11D2,0xAC,0x82,0x00,0x60,0x08,0xA8,0x27,0x4D);

#ifdef __cplusplus

class DECLSPEC_UUID("3B5BA325-3B72-11D2-AC82-006008A8274D")
AutoToolbar;
#endif
#endif /* __AutoPie_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


