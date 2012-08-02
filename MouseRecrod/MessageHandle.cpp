// MessageHandle.cpp: implementation of the CMessageHandle class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "MessageHandle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMessageHandle::CMessageHandle()
{

}

CMessageHandle::~CMessageHandle()
{

}

LPCTSTR CMessageHandle::GetMessageName(UINT message)
{
    switch(message) 
    {
    case WM_NULL: return L"WM_NULL";                                                                   
    case WM_CREATE: return L"WM_CREATE";                                                                  
    case WM_DESTROY: return L"WM_DESTROY";                                                                   
    case WM_MOVE: return L"WM_MOVE";                                                                  
    case WM_SIZE: return L"WM_SIZE";                                                                    
    case WM_ACTIVATE: return L"WM_ACTIVATE";                                                              
    case WM_SETFOCUS: return L"WM_SETFOCUS";                                                            
    case WM_KILLFOCUS: return L"WM_KILLFOCUS";                                                             
    case WM_ENABLE: return L"WM_ENABLE";                                                                
    case WM_SETREDRAW: return L"WM_SETREDRAW";                                                          
    case WM_SETTEXT: return L"WM_SETTEXT";                                                               
    case WM_GETTEXT: return L"WM_GETTEXT";                                                              
    case WM_GETTEXTLENGTH: return L"WM_GETTEXTLENGTH";                                                      
    case WM_PAINT: return L"WM_PAINT";                                                                  
    case WM_CLOSE: return L"WM_CLOSE";                                                                 
    case WM_QUERYENDSESSION: return L"WM_QUERYENDSESSION";                                                   
    case WM_QUIT: return L"WM_QUIT";                                                                   
    case WM_QUERYOPEN: return L"WM_QUERYOPEN";                                                          
    case WM_ERASEBKGND: return L"WM_ERASEBKGND";                                                         
    case WM_SYSCOLORCHANGE: return L"WM_SYSCOLORCHANGE";                                                   
    case WM_ENDSESSION: return L"WM_ENDSESSION";                                                          
    case WM_SHOWWINDOW: return L"WM_SHOWWINDOW";                                                            
    case WM_WININICHANGE: return L"WM_WININICHANGE";                                                                                                 
    case WM_DEVMODECHANGE: return L"WM_DEVMODECHANGE";                                                                                           
    case WM_ACTIVATEAPP: return L"WM_ACTIVATEAPP";                                                                                                  
    case WM_FONTCHANGE: return L"WM_FONTCHANGE";                                                                                
    case WM_TIMECHANGE: return L"WM_TIMECHANGE";                                                                                 
    case WM_CANCELMODE: return L"WM_CANCELMODE";                                                                               
    case WM_SETCURSOR: return L"WM_SETCURSOR";                                                                                 
    case WM_MOUSEACTIVATE: return L"WM_MOUSEACTIVATE";                                                                                              
    case WM_CHILDACTIVATE: return L"WM_CHILDACTIVATE";                                                                                                
    case WM_QUEUESYNC: return L"WM_QUEUESYNC";                                                                                 
    case WM_GETMINMAXINFO: return L"WM_GETMINMAXINFO";                                                                                              
    case WM_PAINTICON: return L"WM_PAINTICON";                                                                                    
    case WM_ICONERASEBKGND: return L"WM_ICONERASEBKGND";                                                                                            
    case WM_NEXTDLGCTL: return L"WM_NEXTDLGCTL";                                                                               
    case WM_SPOOLERSTATUS: return L"WM_SPOOLERSTATUS";                                                                                           
    case WM_DRAWITEM : return L"WM_DRAWITEM";                                                                                 
    case WM_MEASUREITEM: return L"WM_MEASUREITEM";                                                                                              
    case WM_DELETEITEM: return L"WM_DELETEITEM";                                                                                
    case WM_VKEYTOITEM: return L"WM_VKEYTOITEM";                                                                               
    case WM_CHARTOITEM: return L"WM_CHARTOITEM";                                                                               
    case WM_SETFONT: return L"WM_SETFONT";                                                                                   
    case WM_GETFONT: return L"WM_GETFONT";                                                                                  
    case WM_SETHOTKEY: return L"WM_SETHOTKEY";                                                                                
    case WM_GETHOTKEY: return L"WM_GETHOTKEY";                                                                               
    case WM_QUERYDRAGICON: return L"WM_QUERYDRAGICON";                                                                                          
    case WM_COMPAREITEM: return L"WM_COMPAREITEM";                                                                                              
//    case WM_GETOBJECT: return L"WM_GETOBJECT";                                                                                
    case WM_COMPACTING: return L"WM_COMPACTING";                                                                              
    case WM_COMMNOTIFY: return L"WM_COMMNOTIFY";                                                                             
    case WM_WINDOWPOSCHANGING: return L"WM_WINDOWPOSCHANGING";                                                                                   
    case WM_WINDOWPOSCHANGED: return L"WM_WINDOWPOSCHANGED";                                                                                   
    case WM_POWER: return L"WM_POWER";                                                                                   
    case WM_COPYDATA: return L"WM_COPYDATA";                                                                                
    case WM_CANCELJOURNAL: return L"WM_CANCELJOURNAL";                                                                                          
    case WM_NOTIFY: return L"WM_NOTIFY";                                                                                    
    case WM_INPUTLANGCHANGEREQUEST: return L"WM_INPUTLANGCHANGEREQUEST";                                                                             
    case WM_INPUTLANGCHANGE: return L"WM_INPUTLANGCHANGE";                                                                                       
    case WM_TCARD: return L"WM_TCARD";                                                                                    
    case WM_HELP: return L"WM_HELP";                                                                                      
    case WM_USERCHANGED: return L"WM_USERCHANGED";                                                                                           
    case WM_NOTIFYFORMAT: return L"WM_NOTIFYFORMAT";                                                                                            
    case WM_CONTEXTMENU: return L"WM_CONTEXTMENU";                                                                                            
    case WM_STYLECHANGING: return L"WM_STYLECHANGING";                                                                                           
    case WM_STYLECHANGED: return L"WM_STYLECHANGED";                                                                                           
    case WM_DISPLAYCHANGE: return L"WM_DISPLAYCHANGE";                                                                                           
    case WM_GETICON: return L"WM_GETICON";                                                                                  
    case WM_SETICON: return L"WM_SETICON";                                                                                   
    case WM_NCCREATE: return L"WM_NCCREATE";                                                                                
    case WM_NCDESTROY: return L"WM_NCDESTROY";                                                                              
    case WM_NCCALCSIZE: return L"WM_NCCALCSIZE";                                                                               
    case WM_NCHITTEST: return L"WM_NCHITTEST";                                                                                 
    case WM_NCPAINT: return L"WM_NCPAINT";                                                                                   
    case WM_NCACTIVATE: return L"WM_NCACTIVATE";                                                                               
    case WM_GETDLGCODE: return L"WM_GETDLGCODE";                                                                             
    case WM_SYNCPAINT: return L"WM_SYNCPAINT";                                                                                
    case WM_NCMOUSEMOVE: return L"WM_NCMOUSEMOVE";                                                                                           
    case WM_NCLBUTTONDOWN: return L"WM_NCLBUTTONDOWN";                                                                                         
    case WM_NCLBUTTONUP: return L"WM_NCLBUTTONUP";                                                                                             
    case WM_NCLBUTTONDBLCLK: return L"WM_NCLBUTTONDBLCLK";                                                                                        
    case WM_NCRBUTTONDOWN: return L"WM_NCRBUTTONDOWN";                                                                                        
    case WM_NCRBUTTONUP: return L"WM_NCRBUTTONUP";                                                                                            
    case WM_NCRBUTTONDBLCLK: return L"WM_NCRBUTTONDBLCLK";                                                                                       
    case WM_NCMBUTTONDOWN: return L"WM_NCMBUTTONDOWN";                                                                                        
    case WM_NCMBUTTONUP: return L"WM_NCMBUTTONUP";                                                                                            
    case WM_NCMBUTTONDBLCLK: return L"WM_NCMBUTTONDBLCLK";                                                                                       
//    case WM_KEYFIRST: return L"WM_KEYFIRST";                                                                                  
    case WM_KEYDOWN: return L"WM_KEYDOWN";                                                                                
    case WM_KEYUP: return L"WM_KEYUP";                                                                                     
    case WM_CHAR: return L"WM_CHAR";                                                                                      
    case WM_DEADCHAR: return L"WM_DEADCHAR";                                                                                
    case WM_SYSKEYDOWN: return L"WM_SYSKEYDOWN";                                                                            
    case WM_SYSKEYUP: return L"WM_SYSKEYUP";                                                                                 
    case WM_SYSCHAR: return L"WM_SYSCHAR";                                                                                  
    case WM_SYSDEADCHAR: return L"WM_SYSDEADCHAR";                                                                                             
    case WM_KEYLAST: return L"WM_KEYLAST";                                                                                   
    case WM_IME_STARTCOMPOSITION: return L"WM_STARTCOMPOSITION";                                                                                   
    case WM_IME_ENDCOMPOSITION: return L"WM_ENDCOMPOSITION";                                                                                     
//    case WM_IME_COMPOSITION: return L"WM_COMPOSITION";                                                                                          
    case WM_IME_KEYLAST: return L"WM_KEYLAST";                                                                                               
    case WM_INITDIALOG: return L"WM_INITDIALOG";                                                                                  
    case WM_COMMAND: return L"WM_COMMAND";                                                                                
    case WM_SYSCOMMAND: return L"WM_SYSCOMMAND";                                                                            
    case WM_TIMER: return L"WM_TIMER";                                                                                      
    case WM_HSCROLL: return L"WM_HSCROLL";                                                                                  
    case WM_VSCROLL: return L"WM_VSCROLL";                                                                                  
    case WM_INITMENU: return L"WM_INITMENU";                                                                                   
    case WM_INITMENUPOPUP: return L"WM_INITMENUPOPUP";                                                                                            
    case WM_MENUSELECT: return L"WM_MENUSELECT";                                                                             
    case WM_MENUCHAR: return L"WM_MENUCHAR";                                                                               
    case WM_ENTERIDLE: return L"WM_ENTERIDLE";                                                                                 
//    case WM_MENURBUTTONUP: return L"WM_";                                                                                         
//    case WM_MENUDRAG: return L"WM_MENURBUTTONUP";                                                                               
//    case WM_MENUGETOBJECT: return L"WM_MENUGETOBJECT";                                                                                           
//    case WM_UNINITMENUPOPUP: return L"WM_UNINITMENUPOPUP";                                                                                          
//    case WM_MENUCOMMAND: return L"WM_MENUCOMMAND";                                                                                           
    case WM_CTLCOLORMSGBOX: return L"WM_CTLCOLORMSGBOX";                                                                                         
    case WM_CTLCOLOREDIT: return L"WM_CTLCOLOREDIT";                                                                                              
    case WM_CTLCOLORLISTBOX: return L"WM_CTLCOLORLISTBOX";                                                                                          
    case WM_CTLCOLORBTN: return L"WM_CTLCOLORBTN";                                                                                              
    case WM_CTLCOLORDLG: return L"WM_CTLCOLORDLG";                                                                                              
    case WM_CTLCOLORSCROLLBAR: return L"WM_CTLCOLORSCROLLBAR";                                                                                      
    case WM_CTLCOLORSTATIC: return L"WM_CTLCOLORSTATIC";                                                                                            
//    case WM_MOUSEFIRST: return L"WM_MOUSEFIRST";                                                                               
    case WM_MOUSEMOVE: return L"WM_MOUSEMOVE";                                                                              
    case WM_LBUTTONDOWN: return L"WM_LBUTTONDOWN";                                                                                             
    case WM_LBUTTONUP: return L"WM_LBUTTONUP";                                                                                
    case WM_LBUTTONDBLCLK: return L"WM_LBUTTONDBLCLK";                                                                                            
    case WM_RBUTTONDOWN: return L"WM_RBUTTONDOWN";                                                                                            
    case WM_RBUTTONUP: return L"WM_RBUTTONUP";                                                                                
    case WM_RBUTTONDBLCLK: return L"WM_RBUTTONDBLCLK";                                                                                            
    case WM_MBUTTONDOWN: return L"WM_MBUTTONDOWN";                                                                                            
    case WM_MBUTTONUP: return L"WM_MBUTTONUP";                                                                               
    case WM_MBUTTONDBLCLK: return L"WM_MBUTTONDBLCLK";                                                                                           
    case WM_MOUSEWHEEL: return L"WM_MOUSEWHEEL";                                                                             
//    case WM_MOUSELAST: return L"WM_MOUSELAST";                                                                                
    case WM_PARENTNOTIFY: return L"WM_PARENTNOTIFY";                                                                                              
    case WM_ENTERMENULOOP: return L"WM_ENTERMENULOOP";                                                                                          
    case WM_EXITMENULOOP: return L"WM_EXITMENULOOP";                                                                                             
    case WM_NEXTMENU : return L"WM_NEXTMENU";                                                                                 
    case WM_SIZING: return L"WM_SIZING";                                                                                       
    case WM_CAPTURECHANGED: return L"WM_CAPTURECHANGED";                                                                                         
    case WM_MOVING: return L"WM_MOVING";                                                                                 
    case WM_POWERBROADCAST: return L"WM_POWERBROADCAST";                                                                                    
    case WM_DEVICECHANGE: return L"WM_DEVICECHANGE";                                                                                          
    case WM_MDICREATE: return L"WM_MDICREATE";                                                                             
    case WM_MDIDESTROY: return L"WM_MDIDESTROY";                                                                           
    case WM_MDIACTIVATE: return L"WM_MDIACTIVATE";                                                                                             
    case WM_MDIRESTORE: return L"WM_MDIRESTORE";                                                                           
    case WM_MDINEXT: return L"WM_MDINEXT";                                                                                
    case WM_MDIMAXIMIZE: return L"WM_MDIMAXIMIZE";                                                                                             
    case WM_MDITILE: return L"WM_MDITILE";                                                                                  
    case WM_MDICASCADE: return L"WM_MDICASCADE";                                                                           
    case WM_MDIICONARRANGE: return L"WM_MDIICONARRANGE";                                                                                       
    case WM_MDIGETACTIVE: return L"WM_MDIGETACTIVE";                                                                                           
    case WM_MDISETMENU: return L"WM_MDISETMENU";                                                                           
    case WM_ENTERSIZEMOVE: return L"WM_ENTERSIZEMOVE";                                                                                         
    case WM_EXITSIZEMOVE: return L"WM_EXITSIZEMOVE";                                                                                            
    case WM_DROPFILES: return L"WM_DROPFILES";                                                                              
    case WM_MDIREFRESHMENU: return L"WM_MDIREFRESHMENU";                                                                                   
    case WM_IME_SETCONTEXT: return L"WM_SETCONTEXT";                                                                                     
    case WM_IME_NOTIFY: return L"WM_NOTIFY";                                                                           
    case WM_IME_CONTROL: return L"WM_CONTROL";                                                                                        
    case WM_IME_COMPOSITIONFULL: return L"WM_COMPOSITIONFULL";                                                                                
    case WM_IME_SELECT: return L"WM_SELECT";                                                                                           
    case WM_IME_CHAR: return L"WM_CHAR";                                                                            
//    case WM_IME_REQUEST: return L"WM_REQUEST";                                                                                         
    case WM_IME_KEYDOWN: return L"WM_KEYDOWN";                                                                                       
    case WM_IME_KEYUP: return L"WM_KEYUP";                                                                           
    case WM_MOUSEHOVER: return L"WM_MOUSEHOVER";                                                                                       
    case WM_MOUSELEAVE: return L"WM_MOUSELEAVE";                                                                                         
    case WM_CUT: return L"WM_CUT";                                                                                  
    case WM_COPY: return L"WM_COPY";                                                                                
    case WM_PASTE: return L"WM_PASTE";                                                                                
    case WM_CLEAR: return L"WM_CLEAR";                                                                               
    case WM_UNDO: return L"WM_UNDO";                                                                                
    case WM_RENDERFORMAT: return L"WM_RENDERFORMAT";                                                                                     
    case WM_RENDERALLFORMATS: return L"WM_RENDERALLFORMATS";                                                                                
    case WM_DESTROYCLIPBOARD: return L"WM_DESTROYCLIPBOARD";                                                                                 
    case WM_DRAWCLIPBOARD: return L"WM_DRAWCLIPBOARD";                                                                                     
    case WM_PAINTCLIPBOARD: return L"WM_PAINTCLIPBOARD";                                                                                      
    case WM_VSCROLLCLIPBOARD: return L"WM_VSCROLLCLIPBOARD";                                                                                  
    case WM_SIZECLIPBOARD: return L"WM_SIZECLIPBOARD";                                                                                        
    case WM_ASKCBFORMATNAME: return L"WM_ASKCBFORMATNAME";                                                                                 
    case WM_CHANGECBCHAIN: return L"WM_CHANGECBCHAIN";                                                                                     
    case WM_HSCROLLCLIPBOARD: return L"WM_HSCROLLCLIPBOARD";                                                                                  
    case WM_QUERYNEWPALETTE: return L"WM_QUERYNEWPALETTE";                                                                                 
    case WM_PALETTEISCHANGING: return L"WM_PALETTEISCHANGING";                                                                                  
    case WM_PALETTECHANGED: return L"WM_PALETTECHANGED";                                                                                   
    case WM_HOTKEY: return L"WM_HOTKEY";                                                                              
    case WM_PRINT: return L"WM_PRINT";                                                                                 
    case WM_PRINTCLIENT: return L"WM_PRINTCLIENT";                                                                                           
    case WM_HANDHELDFIRST: return L"WM_HANDHELDFIRST";                                                                                      
    case WM_HANDHELDLAST: return L"WM_HANDHELDLAST";                                                                                       
    case WM_AFXFIRST: return L"WM_AFXFIRST";                                                                             
    case WM_AFXLAST: return L"WM_AFXLAST";                                                                             
    case WM_PENWINFIRST: return L"WM_PENWINFIRST";                                                                                          
    case WM_PENWINLAST: return L"WM_PENWINLAST"; 
    default:
        return L"UNDEFIND";
    }
}
