#ifndef SRC_NODE_REGISTER_BUILTINS_H_
#define SRC_NODE_REGISTER_BUILTINS_H_

// statically linking node into another target on windows commonly results in
// the linker throwing out most of node's builtin auto-registration functions.
// including this file in that target will force the linker to keep them
// around. obviously this is error prone as list needs to be kept in-sync with
// the list of builtins but it gets the job done.

#include "node.h"

#if defined(_MSC_VER) && !defined(NODE_SHARED_MODE)

#if defined(_WIN64)
#define PREFIX ""
#else
#define PREFIX "_"
#endif

#pragma comment(linker, "/include:" PREFIX "_register_async_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_buffer_")
#pragma comment(linker, "/include:" PREFIX "_register_cares_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_config_")
#pragma comment(linker, "/include:" PREFIX "_register_contextify_")
#pragma comment(linker, "/include:" PREFIX "_register_crypto_")
#pragma comment(linker, "/include:" PREFIX "_register_fs_")
#pragma comment(linker, "/include:" PREFIX "_register_fs_event_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_http_parser_")
#pragma comment(linker, "/include:" PREFIX "_register_icu_")
#pragma comment(linker, "/include:" PREFIX "_register_js_stream_")
#pragma comment(linker, "/include:" PREFIX "_register_os_")
#pragma comment(linker, "/include:" PREFIX "_register_pipe_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_process_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_signal_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_spawn_sync_")
#pragma comment(linker, "/include:" PREFIX "_register_stream_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_tcp_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_timer_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_tls_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_tty_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_udp_wrap_")
#pragma comment(linker, "/include:" PREFIX "_register_url_")
#pragma comment(linker, "/include:" PREFIX "_register_util_")
#pragma comment(linker, "/include:" PREFIX "_register_uv_")
#pragma comment(linker, "/include:" PREFIX "_register_v8_")
#pragma comment(linker, "/include:" PREFIX "_register_zlib_")

#endif

#endif  // SRC_NODE_REGISTER_BUILTINS_H_
