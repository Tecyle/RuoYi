API 拦截的实现原理
-----------------

1.  利用 CreateProcess 函数创建一个供调试的进程。
2.  建立 WaitForDebugEvent 和 ContinueDebugEvent 构成的调试循环体。
3.  利用 SuspendThread 函数挂起目标线程。
4.  利用 VirtualProtectEx 函数修改目标页的读写权限。
5.  利用 ReadProcessMemory 函数读取目标页。
6.  利用 GetThreadContext 函数保存线程环境。
7.  利用 WriteProcessMemory 函数写入新代码页。
8.  保存一份 CONTEXT 结构的临时拷贝。
9.  在这份临时拷贝中设置新的 EIP 的值。
10. 新代码页中利用 LoadLibrary 函数加载拦截 API 的 DLL。
11. 新代码页的最后一个代码必须是 INT 0x03。
12. 恢复原线程的执行，它将执行注入的代码，直到执行到 INT 0x03 抛出异常被我们捕获，线程再次被挂起。
13. 利用 WriteProcessMemory 函数恢复原始代码页。
14. 恢复原始代码页的读写属性。
15. 利用 SetThreadContext 恢复线程原始的环境。
16. 恢复原线程执行。

原则上说，只要目标进程不调用违规 API，拦截对其性能不会造成太大的影响。

注入 DLL 的主要行为
------------------

注入 DLL 在 DllMain 中检测到自己被附加的时候，去搜索目标进程中需要拦截的 API 地址，并修改入口指令，将其重定向至自己的 API。
目前版本的注入 DLL 仅实现屏蔽非法 API，即一旦发生违规调用，将抛出异常通知调试进程，最后直接终止本进程。

需要监视的 API
-------------

网络功能相关
===========

文件操作
=======

进程及线程操作
=============

DLL 载入拦截
------------

对于程序要求载入某些特殊的 dll 的时候，调试进程发现之后当做违规处理。