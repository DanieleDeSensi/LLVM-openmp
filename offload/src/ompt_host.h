#ifndef OMPT_HOST_H_INCLUDED
#define OMPT_HOST_H_INCLUDED

#include "ompt.h"

typedef struct ompt_target_info_s {
    /* boolean flag to differentiate target data and target update*/
    int                             is_target_data;
} ompt_target_info_t;


// filled in __ompt_target_initialize
extern ompt_get_task_id_t ompt_get_task_id;

typedef int (*ompt_enabled_t)();
extern ompt_enabled_t ompt_enabled;

typedef ompt_callback_t (*ompt_get_target_callback_t)(ompt_event_t);
extern ompt_get_target_callback_t __ompt_get_target_callback;

void __ompt_target_initialize();

// defined in runtime which has C interface
#ifdef __cplusplus
extern "C" {
#endif
extern void ompt_target_initialize(ompt_get_task_id_t *, ompt_enabled_t *,
                                   ompt_get_target_callback_t *);
#ifdef __cplusplus
};
#endif

// helper functions for callbacks
static inline ompt_new_target_task_callback_t
ompt_get_new_target_task_callback(ompt_event_t evid)
{
    return (ompt_new_target_task_callback_t) __ompt_get_target_callback(evid);
}

static inline ompt_new_target_data_callback_t
ompt_get_new_target_data_callback(ompt_event_t evid)
{
    return (ompt_new_target_data_callback_t) __ompt_get_target_callback(evid);
}

static inline ompt_new_data_map_callback_t
ompt_get_new_data_map_callback(ompt_event_t evid)
{
    return (ompt_new_data_map_callback_t) __ompt_get_target_callback(evid);
}

static inline ompt_data_map_done_callback_t
ompt_get_target_data_map_done_callback(ompt_event_t evid)
{
    return (ompt_data_map_done_callback_t) __ompt_get_target_callback(evid);
}

static inline ompt_task_callback_t
ompt_get_task_callback(ompt_event_t evid)
{
    return (ompt_task_callback_t) __ompt_get_target_callback(evid);
}

ompt_task_id_t __ompt_target_task_id_new();

//ompt_data_map_id_t __ompt_data_map_id_new();

#endif