﻿/*
 * Copyright(c) 2006 iniCom Networks, Inc.
 *
 * This file is part of ioFTPD.
 *
 * ioFTPD is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * ioFTPD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ioFTPD; see the file COPYING.  if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

//z ftp 建立的是长连接
typedef struct _CONNECTION_INFO
{
    //z 客户端地址
    struct sockaddr_in	ClientAddress;
    //z server 地址
    struct sockaddr_in	LocalAddress;
    LPSTR				szIdent;
    //z 机器名
    LPSTR				szHostName;
    //z 尝试登录的次数？
    UINT				uLoginAttempt;
    //z 时间
    time_t				tLogin;
    LPIOSERVICE			lpService;
    LPIOSERVICE			lpDoService; // needed by SERVICE cookie
    LPIODEVICE          lpDevice;    // needed by ident routines and DEVICE cookie, else ignored
    LPIODEVICE          lpDoDevice;  // needed by DEVICE cookie
    DWORD				dwStatus;
    DWORD				dwUniqueId;
    struct _CLIENT     *lpClient;    // readonly, don't modify outside of lock on id!
    LPHOSTINFO			lpHostInfo;

} CONNECTION_INFO, * PCONNECTION_INFO;
