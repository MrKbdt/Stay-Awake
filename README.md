# Stay_Awake
Windows 10 Utility: Stops screen saver and inactivity timeout from kicking in with virtual keyboard activity.

The following program toggles the NUM LOCK key light.
The SetNumLock function defined here simulates pressing the NUM LOCK key
using keybd_event() with a virtual key of VK_NUMLOCK. It takes a boolean
value that indicates whether the light should be turned off (FALSE) or on (TRUE).
The same technique can be used for the CAPS LOCK key (VK_CAPITAL) and the
SCROLL LOCK key (VK_SCROLL).
keybd_event function (winuser.h)
https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-keybd_event
Virtual-Key Codes
https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

Also creates a visual in the command shell which emulates a waiting command prompt.
