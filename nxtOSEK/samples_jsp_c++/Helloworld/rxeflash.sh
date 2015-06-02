echo Executing NeXTTool to upload helloworld.rxe...
wineconsole /cygdrive/C/cygwin/nexttool/NeXTTool.exe /COM=usb -download=helloworld.rxe
wineconsole /cygdrive/C/cygwin/nexttool/NeXTTool.exe /COM=usb -listfiles=helloworld.rxe
echo NeXTTool is terminated.
