///**
//  ******************************************************************************
//  * @file    lwipopts.h
//  * @author  MCD Application Team
//  * @version V1.1.0
//  * @date    31-July-2013
//  * @brief   lwIP Options Configuration.
//  *          This file is based on Utilities\lwip_v1.4.1\src\include\lwip\opt.h 
//  *          and contains the lwIP configuration for the STM32F4x7 demonstration.
//  ******************************************************************************
//  * @attention
//  *
//  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
//  *
//  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
//  * You may not use this file except in compliance with the License.
//  * You may obtain a copy of the License at:
//  *
//  *        http://www.st.com/software_license_agreement_liberty_v2
//  *
//  * Unless required by applicable law or agreed to in writing, software 
//  * distributed under the License is distributed on an "AS IS" BASIS, 
//  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  * See the License for the specific language governing permissions and
//  * limitations under the License.
//  *
//  ******************************************************************************
//  */

//#ifndef __LWIPOPTS_H__
//#define __LWIPOPTS_H__

///**
// * SYS_LIGHTWEIGHT_PROT==1: if you want inter-task protection for certain
// * critical regions during buffer allocation, deallocation and memory
// * allocation and deallocation.
// */
//#define SYS_LIGHTWEIGHT_PROT    1

//#define ETHARP_TRUST_IP_MAC     0
//#define IP_REASSEMBLY           0
//#define IP_FRAG                 0
//#define ARP_QUEUEING            1

///**
// * NO_SYS==1: Provides VERY minimal functionality. Otherwise,
// * use lwIP facilities.
// */
//#define NO_SYS                  0

///* ---------- Memory options ---------- */
///* MEM_ALIGNMENT: should be set to the alignment of the CPU for which
//   lwIP is compiled. 4 byte alignment -> define MEM_ALIGNMENT to 4, 2
//   byte alignment -> define MEM_ALIGNMENT to 2. */
//#define MEM_ALIGNMENT           4

///* MEM_SIZE: the size of the heap memory. If the application will send
//a lot of data that needs to be copied, this should be set high. */
//#define MEM_SIZE                (10*1024)

///* MEMP_NUM_PBUF: the number of memp struct pbufs. If the application
//   sends a lot of data out of ROM (or other static memory), this
//   should be set high. */
//#define MEMP_NUM_PBUF           100
///* MEMP_NUM_UDP_PCB: the number of UDP protocol control blocks. One
//   per active UDP "connection". */
//#define MEMP_NUM_UDP_PCB        6
///* MEMP_NUM_TCP_PCB: the number of simulatenously active TCP
//   connections. */
//#define MEMP_NUM_TCP_PCB        10
///* MEMP_NUM_TCP_PCB_LISTEN: the number of listening TCP
//   connections. */
//#define MEMP_NUM_TCP_PCB_LISTEN 5
///* MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP
//   segments. */
//#define MEMP_NUM_TCP_SEG        20
///* MEMP_NUM_SYS_TIMEOUT: the number of simulateously active
//   timeouts. */
//#define MEMP_NUM_SYS_TIMEOUT    10


///* ---------- Pbuf options ---------- */
///* PBUF_POOL_SIZE: the number of buffers in the pbuf pool. */
//#define PBUF_POOL_SIZE          20

///* PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. */
//#define PBUF_POOL_BUFSIZE       512


///* ---------- TCP options ---------- */
//#define LWIP_TCP                1
//#define TCP_TTL                 255

///* Controls if TCP should queue segments that arrive out of
//   order. Define to 0 if your device is low on memory. */
//#define TCP_QUEUE_OOSEQ         0

///* TCP Maximum segment size. */
//#define TCP_MSS                 (1500 - 40)	  /* TCP_MSS = (Ethernet MTU - IP header size - TCP header size) */

///* TCP sender buffer space (bytes). */
//#define TCP_SND_BUF             (5*TCP_MSS)

///*  TCP_SND_QUEUELEN: TCP sender buffer space (pbufs). This must be at least
//  as much as (2 * TCP_SND_BUF/TCP_MSS) for things to work. */

//#define TCP_SND_QUEUELEN        (4* TCP_SND_BUF/TCP_MSS)

///* TCP receive window. */
//#define TCP_WND                 (2*TCP_MSS)


///* ---------- ICMP options ---------- */
//#define LWIP_ICMP                       1


///* ---------- DHCP options ---------- */
///* Define LWIP_DHCP to 1 if you want DHCP configuration of
//   interfaces. DHCP is not implemented in lwIP 0.5.1, however, so
//   turning this on does currently not work. */
//#define LWIP_DHCP               0


///* ---------- UDP options ---------- */
//#define LWIP_UDP                1
//#define UDP_TTL                 255


///* ---------- Statistics options ---------- */
//#define LWIP_STATS 0
//#define LWIP_PROVIDE_ERRNO 0

///* ---------- link callback options ---------- */
///* LWIP_NETIF_LINK_CALLBACK==1: Support a callback function from an interface
// * whenever the link changes (i.e., link down)
// */
//#define LWIP_NETIF_LINK_CALLBACK        1

///*
//   --------------------------------------
//   ---------- Checksum options ----------
//   --------------------------------------
//*/

///* 
//The STM32F4x7 allows computing and verifying the IP, UDP, TCP and ICMP checksums by hardware:
// - To use this feature let the following define uncommented.
// - To disable it and process by CPU comment the  the checksum.
//*/
////#define CHECKSUM_BY_HARDWARE 


//#ifdef CHECKSUM_BY_HARDWARE
//  /* CHECKSUM_GEN_IP==0: Generate checksums by hardware for outgoing IP packets.*/
//  #define CHECKSUM_GEN_IP                 0
//  /* CHECKSUM_GEN_UDP==0: Generate checksums by hardware for outgoing UDP packets.*/
//  #define CHECKSUM_GEN_UDP                0
//  /* CHECKSUM_GEN_TCP==0: Generate checksums by hardware for outgoing TCP packets.*/
//  #define CHECKSUM_GEN_TCP                0 
//  /* CHECKSUM_CHECK_IP==0: Check checksums by hardware for incoming IP packets.*/
//  #define CHECKSUM_CHECK_IP               0
//  /* CHECKSUM_CHECK_UDP==0: Check checksums by hardware for incoming UDP packets.*/
//  #define CHECKSUM_CHECK_UDP              0
//  /* CHECKSUM_CHECK_TCP==0: Check checksums by hardware for incoming TCP packets.*/
//  #define CHECKSUM_CHECK_TCP              0
//  /* CHECKSUM_CHECK_ICMP==0: Check checksums by hardware for incoming ICMP packets.*/
//  #define CHECKSUM_GEN_ICMP               0
//#else
//  /* CHECKSUM_GEN_IP==1: Generate checksums in software for outgoing IP packets.*/
//  #define CHECKSUM_GEN_IP                 1
//  /* CHECKSUM_GEN_UDP==1: Generate checksums in software for outgoing UDP packets.*/
//  #define CHECKSUM_GEN_UDP                1
//  /* CHECKSUM_GEN_TCP==1: Generate checksums in software for outgoing TCP packets.*/
//  #define CHECKSUM_GEN_TCP                1
//  /* CHECKSUM_CHECK_IP==1: Check checksums in software for incoming IP packets.*/
//  #define CHECKSUM_CHECK_IP               1
//  /* CHECKSUM_CHECK_UDP==1: Check checksums in software for incoming UDP packets.*/
//  #define CHECKSUM_CHECK_UDP              1
//  /* CHECKSUM_CHECK_TCP==1: Check checksums in software for incoming TCP packets.*/
//  #define CHECKSUM_CHECK_TCP              1
//  /* CHECKSUM_CHECK_ICMP==1: Check checksums by hardware for incoming ICMP packets.*/
//  #define CHECKSUM_GEN_ICMP               1
//#endif


///*
//   ----------------------------------------------
//   ---------- Sequential layer options ----------
//   ----------------------------------------------
//*/
///**
// * LWIP_NETCONN==1: Enable Netconn API (require to use api_lib.c)
// */
//#define LWIP_NETCONN                    1

///*
//   ------------------------------------
//   ---------- Socket options ----------
//   ------------------------------------
//*/
///**
// * LWIP_SOCKET==1: Enable Socket API (require to use sockets.c)
// */
//#define LWIP_SOCKET                     1

///*
//   -----------------------------------
//   ---------- DEBUG options ----------
//   -----------------------------------
//*/

//#define LWIP_DEBUG                      0


///*
//   ---------------------------------
//   ---------- OS options ----------
//   ---------------------------------
//*/

//#define TCPIP_THREAD_NAME              "TCP/IP"
//#define TCPIP_THREAD_STACKSIZE          512//1000
//#define TCPIP_MBOX_SIZE                 32
//#define DEFAULT_UDP_RECVMBOX_SIZE       32//2000
//#define DEFAULT_TCP_RECVMBOX_SIZE       32//2000
//#define DEFAULT_ACCEPTMBOX_SIZE         32//2000
//#define DEFAULT_THREAD_STACKSIZE        512//500
//#define TCPIP_THREAD_PRIO               (5) 

//#define LWIP_COMPAT_MUTEX 1
//#define LWIP_COMPAT_MUTEX_ALLOWED
//#define LWIP_SKIP_CONST_CHECK

//#endif /* __LWIPOPTS_H__ */

///************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__
 
#define SYS_LIGHTWEIGHT_PROT    		1							//为1时使用实时操作系统的轻量级保护,保护关键代码不被中断打断
#define NO_SYS                  		0  							//使用UCOS操作系统
#define MEM_ALIGNMENT           		4  							//使用4字节对齐模式
#define MEM_SIZE                		15*1024						//内存堆heap大小
#define MEMP_NUM_PBUF           		16							//MEMP_NUM_PBUF:memp结构的pbuf数量,如果应用从ROM或者静态存储区发送大量数据时,这个值应该设置大一点
#define MEMP_NUM_UDP_PCB        		5							//MEMP_NUM_UDP_PCB:UDP协议控制块(PCB)数量.每个活动的UDP"连接"需要一个PCB.
#define MEMP_NUM_TCP_PCB        		8							//MEMP_NUM_TCP_PCB:同时建立激活的TCP数量
#define MEMP_NUM_TCP_PCB_LISTEN 		7							//MEMP_NUM_TCP_PCB_LISTEN:能够监听的TCP连接数量
#define MEMP_NUM_TCP_SEG        		20							//MEMP_NUM_TCP_SEG:最多同时在队列中的TCP段数量
#define MEMP_NUM_SYS_TIMEOUT    		8							//MEMP_NUM_SYS_TIMEOUT:能够同时激活的timeout个数

//pbuf选项
#define PBUF_POOL_SIZE          		25							//PBUF_POOL_SIZE:pbuf内存池个数
#define PBUF_POOL_BUFSIZE     			512							//PBUF_POOL_BUFSIZE:每个pbuf内存池大小

#define LWIP_TCP                		1  							//使用TCP
#define TCP_TTL                			255							//生存时间

#undef TCP_QUEUE_OOSEQ
#define TCP_QUEUE_OOSEQ         		0 							//当TCP的数据段超出队列时的控制位,当设备的内存过小的时候此项应为0

#undef TCPIP_MBOX_SIZE
#define TCPIP_MBOX_SIZE         		32   		//tcpip创建主线程时的消息邮箱大小

#undef DEFAULT_TCP_RECVMBOX_SIZE
#define DEFAULT_TCP_RECVMBOX_SIZE       32  

#undef DEFAULT_ACCEPTMBOX_SIZE
#define DEFAULT_ACCEPTMBOX_SIZE         32  

		
#define TCP_MSS                			(1500 - 40)	  				//最大TCP分段,TCP_MSS = (MTU - IP报头大小 - TCP报头大小
#define TCP_SND_BUF            		 	(2*TCP_MSS)					//TCP发送缓冲区大小(bytes).
#define TCP_SND_QUEUELEN       		 	(4* TCP_SND_BUF/TCP_MSS)	//TCP_SND_QUEUELEN: TCP发送缓冲区大小(pbuf).这个值最小为(2 * TCP_SND_BUF/TCP_MSS)
#define TCP_WND               		  	(2*TCP_MSS)					//TCP发送窗口
#define LWIP_ICMP             		  	1 							//使用ICMP协议
#define LWIP_DHCP             		  	0							//使用DHCP
#define LWIP_DNS                 			1
#define LWIP_UDP              		  	1 							//使用UDP服务
#define UDP_TTL               		  	255 						//UDP数据包生存时间
#define LWIP_STATS 						0
#define LWIP_PROVIDE_ERRNO 				1


#define LWIP_NETCONN                    1 							//LWIP_NETCONN==1:使能NETCON函数(要求使用api_lib.c)
#define LWIP_SOCKET                     1							//LWIP_SOCKET==1:使能Sicket API(要求使用sockets.c)
#define LWIP_COMPAT_MUTEX               1		
#define LWIP_SO_RCVTIMEO                1 							//通过定义LWIP_SO_RCVTIMEO使能netconn结构体中recv_timeout,使用recv_timeout可以避免阻塞线程

//有关系统的选项
#define TCPIP_THREAD_PRIO								6							//定义内核任务的优先级为5
#define TCPIP_THREAD_STACKSIZE          512						//内核任务堆栈大小
#define DEFAULT_UDP_RECVMBOX_SIZE       2000
#define DEFAULT_THREAD_STACKSIZE        512

//LWIP调试选项
#define LWIP_DEBUG                    	0 						//关闭DEBUG选项
#define ICMP_DEBUG                     	LWIP_DBG_OFF 				//开启/关闭ICMPdebug


#define LWIP_COMPAT_MUTEX 1
#define LWIP_COMPAT_MUTEX_ALLOWED
//#define LWIP_SKIP_CONST_CHECK

#define ETHARP_TRUST_IP_MAC     1
#define IP_REASSEMBLY           1
#define IP_FRAG                 1
#define ARP_QUEUEING            1
#define LWIP_DNS_SECURE					0

#define LWIP_COMPAT_SOCKETS             2
#define LWIP_POSIX_SOCKETS_IO_NAMES     1

#define LWIP_TCPIP_CORE_LOCKING_INPUT   1
#endif /* __LWIPOPTS_H__ */













