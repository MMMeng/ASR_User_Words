/*
 *  Application interface library for the ALSA driver
 *  Copyright (c) by Jaroslav Kysela <perex@suse.cz>
 *
 *
 *   This library is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Library General Public License for more details.
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef __ASOUNDLIB_H
#define __ASOUNDLIB_H

#include <linux/asound.h>
#include <linux/asequencer.h>
#include <unistd.h>
#include <fcntl.h>

/*
 *  version.h
 */

#define SND_LIB_MAJOR		0
#define SND_LIB_MINOR		4
#define SND_LIB_SUBMINOR	0
#define SND_LIB_VERSION		((SND_LIB_MAJOR<<16)|\
				 (SND_LIB_MINOR<<8)|\
				  SND_LIB_SUBMINOR)
#define SND_LIB_VERSION_STR	"0.4.0"

/* OBSOLETE DEFINES WHICH WON'T BE IN 0.3.0 FINAL!!! */
#define SOUNDLIB_VERSION_MAJOR		SND_LIB_MAJOR
#define SOUNDLIB_VERSION_MINOR		SND_LIB_MINOR
#define SOUNDLIB_VERSION_SUBMINOR	SND_LIB_SUBMINOR

/*
 *  error.h
 */

#define SND_ERROR_BEGIN				500000
#define SND_ERROR_INCOMPATIBLE_VERSION		(SND_ERROR_BEGIN+0)

#ifdef __cplusplus
extern "C" {
#endif

const char *snd_strerror( int errnum );

#ifdef __cplusplus
}
#endif

/****************************************************************************
 *                                                                          *
 *                              control.h                                   *
 *                          Control Interface                               *
 *                                                                          *
 ****************************************************************************/

typedef struct snd_ctl_callbacks {
	void *private_data;	/* should be used by an application */
	void (*rebuild) (void *private_data);
	void (*xswitch) (void *private_data, int cmd, int iface, snd_switch_list_item_t *item);
	void *reserved[29];	/* reserved for the future use - must be NULL!!! */
} snd_ctl_callbacks_t;

#ifdef __cplusplus
extern "C" {
#endif

typedef struct snd_ctl snd_ctl_t;

int snd_card_load(int card);
int snd_cards(void);
unsigned int snd_cards_mask(void);
int snd_card_name(const char *name);

int snd_defaults_card(void);
int snd_defaults_mixer_card(void);
int snd_defaults_mixer_device(void);
int snd_defaults_pcm_card(void);
int snd_defaults_pcm_device(void);
int snd_defaults_rawmidi_card(void);
int snd_defaults_rawmidi_device(void);

int snd_ctl_open(snd_ctl_t **handle, int card);
int snd_ctl_close(snd_ctl_t *handle);
int snd_ctl_file_descriptor(snd_ctl_t *handle);
int snd_ctl_hw_info(snd_ctl_t *handle, struct snd_ctl_hw_info *info);
int snd_ctl_switch_list(snd_ctl_t *handle, snd_switch_list_t * list);
int snd_ctl_switch_read(snd_ctl_t *handle, snd_switch_t * sw);
int snd_ctl_switch_write(snd_ctl_t *handle, snd_switch_t * sw);
int snd_ctl_hwdep_info(snd_ctl_t *handle, int dev, snd_hwdep_info_t * info);
int snd_ctl_pcm_info(snd_ctl_t *handle, int dev, snd_pcm_info_t * info);
int snd_ctl_pcm_playback_info(snd_ctl_t *handle, int dev, snd_pcm_playback_info_t * info);
int snd_ctl_pcm_capture_info(snd_ctl_t *handle, int dev, snd_pcm_capture_info_t * info);
int snd_ctl_pcm_playback_switch_list(snd_ctl_t *handle, int dev, snd_switch_list_t * list);
int snd_ctl_pcm_playback_switch_read(snd_ctl_t *handle, int dev, snd_switch_t * sw);
int snd_ctl_pcm_playback_switch_write(snd_ctl_t *handle, int dev, snd_switch_t * sw);
int snd_ctl_pcm_capture_switch_list(snd_ctl_t *handle, int dev, snd_switch_list_t * list);
int snd_ctl_pcm_capture_switch_read(snd_ctl_t *handle, int dev, snd_switch_t * sw);
int snd_ctl_pcm_capture_switch_write(snd_ctl_t *handle, int dev, snd_switch_t * sw);
int snd_ctl_mixer_info(snd_ctl_t *handle, int dev, snd_mixer_info_t * info);
int snd_ctl_mixer_switch_list(snd_ctl_t *handle, int dev, snd_switch_list_t *list);
int snd_ctl_mixer_switch_read(snd_ctl_t *handle, int dev, snd_switch_t * sw);
int snd_ctl_mixer_switch_write(snd_ctl_t *handle, int dev, snd_switch_t * sw);
int snd_ctl_rawmidi_info(snd_ctl_t *handle, int dev, snd_rawmidi_info_t * info);
int snd_ctl_rawmidi_output_info(snd_ctl_t *handle, int dev, snd_rawmidi_output_info_t * info);
int snd_ctl_rawmidi_input_info(snd_ctl_t *handle, int dev, snd_rawmidi_input_info_t * info);
int snd_ctl_rawmidi_output_switch_list(snd_ctl_t *handle, int dev, snd_switch_list_t *list);
int snd_ctl_rawmidi_output_switch_read(snd_ctl_t *handle, int dev, snd_switch_t * sw);
int snd_ctl_rawmidi_output_switch_write(snd_ctl_t *handle, int dev, snd_switch_t * sw);
int snd_ctl_rawmidi_input_switch_list(snd_ctl_t *handle, int dev, snd_switch_list_t *list);
int snd_ctl_rawmidi_input_switch_read(snd_ctl_t *handle, int dev, snd_switch_t * sw);
int snd_ctl_rawmidi_input_switch_write(snd_ctl_t *handle, int dev, snd_switch_t * sw);
int snd_ctl_read(snd_ctl_t *handle, snd_ctl_callbacks_t * callbacks);

#ifdef __cplusplus
}
#endif

/****************************************************************************
 *                                                                          *
 *                               mixer.h                                    *
 *                           Mixer Interface                                *
 *                                                                          *
 ****************************************************************************/

typedef struct snd_mixer_callbacks {
	void *private_data;	/* should be used by an application */
	void (*rebuild) (void *private_data);
	void (*element) (void *private_data, int cmd, snd_mixer_eid_t *eid);
	void (*group) (void *private_data, int cmd, snd_mixer_gid_t *gid);
	void *reserved[28];	/* reserved for the future use - must be NULL!!! */
} snd_mixer_callbacks_t;

#ifdef __cplusplus
extern "C" {
#endif

typedef struct snd_mixer snd_mixer_t;

int snd_mixer_open(snd_mixer_t **handle, int card, int device);
int snd_mixer_close(snd_mixer_t *handle);
int snd_mixer_file_descriptor(snd_mixer_t *handle);
int snd_mixer_info(snd_mixer_t *handle, snd_mixer_info_t * info);
int snd_mixer_elements(snd_mixer_t *handle, snd_mixer_elements_t * elements);
int snd_mixer_routes(snd_mixer_t *handle, snd_mixer_routes_t * routes);
int snd_mixer_groups(snd_mixer_t *handle, snd_mixer_groups_t * groups);
int snd_mixer_group_read(snd_mixer_t *handle, snd_mixer_group_t * group);
int snd_mixer_group_write(snd_mixer_t *handle, snd_mixer_group_t * group);
int snd_mixer_element_info(snd_mixer_t *handle, snd_mixer_element_info_t * info);
int snd_mixer_element_read(snd_mixer_t *handle, snd_mixer_element_t * element);
int snd_mixer_element_write(snd_mixer_t *handle, snd_mixer_element_t * element);
int snd_mixer_read_filter(snd_mixer_t *handle, snd_mixer_filter_t * filter);
int snd_mixer_read(snd_mixer_t *handle, snd_mixer_callbacks_t * callbacks);

void snd_mixer_set_bit(unsigned int *bitmap, int bit, int val);
int snd_mixer_get_bit(unsigned int *bitmap, int bit);

const char *snd_mixer_channel_name(int channel);

int snd_mixer_element_has_info(snd_mixer_eid_t *eid);
int snd_mixer_element_info_build(snd_mixer_t *handle, snd_mixer_element_info_t * info);
int snd_mixer_element_info_free(snd_mixer_element_info_t * info);
int snd_mixer_element_has_control(snd_mixer_eid_t *eid);
int snd_mixer_element_build(snd_mixer_t *handle, snd_mixer_element_t * element);
int snd_mixer_element_free(snd_mixer_element_t * element);

#ifdef __cplusplus
}
#endif

/****************************************************************************
 *                                                                          *
 *                                pcm.h                                     *
 *                        Digital Audio Interface                           *
 *                                                                          *
 ****************************************************************************/

#define SND_PCM_OPEN_PLAYBACK	(O_WRONLY)
#define SND_PCM_OPEN_CAPTURE	(O_RDONLY)
#define SND_PCM_OPEN_DUPLEX	(O_RDWR)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct snd_pcm snd_pcm_t;
typedef struct snd_pcm_loopback snd_pcm_loopback_t;

int snd_pcm_open(snd_pcm_t **handle, int card, int device, int mode);
int snd_pcm_close(snd_pcm_t *handle);
int snd_pcm_file_descriptor(snd_pcm_t *handle);
int snd_pcm_block_mode(snd_pcm_t *handle, int enable);
int snd_pcm_info(snd_pcm_t *handle, snd_pcm_info_t * info);
int snd_pcm_playback_info(snd_pcm_t *handle, snd_pcm_playback_info_t * info);
int snd_pcm_capture_info(snd_pcm_t *handle, snd_pcm_capture_info_t * info);
int snd_pcm_playback_format(snd_pcm_t *handle, snd_pcm_format_t * format);
int snd_pcm_capture_format(snd_pcm_t *handle, snd_pcm_format_t * format);
int snd_pcm_playback_params(snd_pcm_t *handle, snd_pcm_playback_params_t * params);
int snd_pcm_capture_params(snd_pcm_t *handle, snd_pcm_capture_params_t * params);
int snd_pcm_playback_status(snd_pcm_t *handle, snd_pcm_playback_status_t * status);
int snd_pcm_capture_status(snd_pcm_t *handle, snd_pcm_capture_status_t * status);
int snd_pcm_drain_playback(snd_pcm_t *handle);
int snd_pcm_flush_playback(snd_pcm_t *handle);
int snd_pcm_flush_capture(snd_pcm_t *handle);
int snd_pcm_playback_pause(snd_pcm_t *handle, int enable);
int snd_pcm_playback_time(snd_pcm_t *handle, int enable);
int snd_pcm_capture_time(snd_pcm_t *handle, int enable);
ssize_t snd_pcm_write(snd_pcm_t *handle, const void *buffer, size_t size);
ssize_t snd_pcm_read(snd_pcm_t *handle, void *buffer, size_t size);

#ifdef __cplusplus
}
#endif

#define SND_PCM_LB_OPEN_PLAYBACK	0
#define SND_PCM_LB_OPEN_CAPTURE		1

#ifdef __cplusplus
extern "C" {
#endif

int snd_pcm_loopback_open(snd_pcm_loopback_t **handle, int card, int device, int mode);
int snd_pcm_loopback_close(snd_pcm_loopback_t *handle);
int snd_pcm_loopback_file_descriptor(snd_pcm_loopback_t *handle);
int snd_pcm_loopback_block_mode(snd_pcm_loopback_t *handle, int enable);
int snd_pcm_loopback_stream_mode(snd_pcm_loopback_t *handle, int mode);
int snd_pcm_loopback_format(snd_pcm_loopback_t *handle, snd_pcm_format_t * format);
ssize_t snd_pcm_loopback_read(snd_pcm_loopback_t *handle, void *buffer, size_t size);

#ifdef __cplusplus
}
#endif

/****************************************************************************
 *                                                                          *
 *                              rawmidi.h                                   *
 *                          RawMIDI interface                               *
 *                                                                          *
 ****************************************************************************/

#define SND_RAWMIDI_OPEN_OUTPUT		(O_WRONLY)
#define SND_RAWMIDI_OPEN_INPUT		(O_RDONLY)
#define SND_RAWMIDI_OPEN_DUPLEX		(O_RDWR)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct snd_rawmidi snd_rawmidi_t;

int snd_rawmidi_open(snd_rawmidi_t **handle, int card, int device, int mode);
int snd_rawmidi_close(snd_rawmidi_t *handle);
int snd_rawmidi_file_descriptor(snd_rawmidi_t *handle);
int snd_rawmidi_block_mode(snd_rawmidi_t *handle, int enable);
int snd_rawmidi_info(snd_rawmidi_t *handle, snd_rawmidi_info_t * info);
int snd_rawmidi_output_params(snd_rawmidi_t *handle, snd_rawmidi_output_params_t * params);
int snd_rawmidi_input_params(snd_rawmidi_t *handle, snd_rawmidi_input_params_t * params);
int snd_rawmidi_output_status(snd_rawmidi_t *handle, snd_rawmidi_output_status_t * status);
int snd_rawmidi_input_status(snd_rawmidi_t *handle, snd_rawmidi_input_status_t * status);
int snd_rawmidi_drain_output(snd_rawmidi_t *handle);
int snd_rawmidi_flush_output(snd_rawmidi_t *handle);
int snd_rawmidi_flush_input(snd_rawmidi_t *handle);
ssize_t snd_rawmidi_write(snd_rawmidi_t *handle, const void *buffer, size_t size);
ssize_t snd_rawmidi_read(snd_rawmidi_t *handle, void *buffer, size_t size);

#ifdef __cplusplus
}
#endif

/****************************************************************************
 *                                                                          *
 *                               timer.h                                    *
 *                           Timer interface                                *
 *                                                                          *
 ****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

typedef struct snd_timer snd_timer_t;

int snd_timer_open(snd_timer_t **handle);
int snd_timer_close(snd_timer_t *handle);
int snd_timer_file_descriptor(snd_timer_t *handle);
int snd_timer_general_info(snd_timer_t *handle, snd_timer_general_info_t * info);
int snd_timer_select(snd_timer_t *handle, snd_timer_select_t *tselect);
int snd_timer_info(snd_timer_t *handle, snd_timer_info_t *timer);
int snd_timer_params(snd_timer_t *handle, snd_timer_params_t *params);
int snd_timer_status(snd_timer_t *handle, snd_timer_status_t *status);
int snd_timer_start(snd_timer_t *handle);
int snd_timer_stop(snd_timer_t *handle);
int snd_timer_continue(snd_timer_t *handle);
ssize_t snd_timer_read(snd_timer_t *handle, void *buffer, size_t size);

#ifdef __cplusplus
}
#endif

/****************************************************************************
 *                                                                          *
 *                                seq.h                                     *
 *                              Sequencer                                   *
 *                                                                          *
 ****************************************************************************/

#define SND_SEQ_OPEN_OUT	(O_WRONLY)
#define SND_SEQ_OPEN_IN		(O_RDONLY)
#define SND_SEQ_OPEN		(O_RDWR)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct snd_seq snd_seq_t;

int snd_seq_open(snd_seq_t **handle, int mode);
int snd_seq_close(snd_seq_t *handle);
int snd_seq_file_descriptor(snd_seq_t *handle);
int snd_seq_block_mode(snd_seq_t *handle, int enable);
int snd_seq_client_id(snd_seq_t *handle);
int snd_seq_system_info(snd_seq_t *handle, snd_seq_system_info_t *info);
int snd_seq_get_client_info(snd_seq_t *handle, snd_seq_client_info_t *info);
int snd_seq_get_any_client_info(snd_seq_t *handle, int client, snd_seq_client_info_t *info);
int snd_seq_set_client_info(snd_seq_t *handle, snd_seq_client_info_t *info);
int snd_seq_create_port(snd_seq_t *handle, snd_seq_port_info_t *info);
int snd_seq_delete_port(snd_seq_t *handle, snd_seq_port_info_t *info);
int snd_seq_get_port_info(snd_seq_t *handle, int port, snd_seq_port_info_t *info);
int snd_seq_get_any_port_info(snd_seq_t *handle, int client, int port, snd_seq_port_info_t *info);
int snd_seq_set_port_info(snd_seq_t *handle, int port, snd_seq_port_info_t *info);
int snd_seq_subscribe_port(snd_seq_t *handle, snd_seq_port_subscribe_t *sub);
int snd_seq_unsubscribe_port(snd_seq_t *handle, snd_seq_port_subscribe_t *sub);
int snd_seq_get_queue_status(snd_seq_t *handle, int q, snd_seq_queue_status_t *status);
int snd_seq_get_queue_tempo(snd_seq_t *handle, int q, snd_seq_queue_tempo_t *tempo);
int snd_seq_set_queue_tempo(snd_seq_t *handle, int q, snd_seq_queue_tempo_t *tempo);
int snd_seq_get_queue_owner(snd_seq_t *handle, int q, snd_seq_queue_owner_t *owner);
int snd_seq_set_queue_owner(snd_seq_t *handle, int q, snd_seq_queue_owner_t *owner);
int snd_seq_get_queue_timer(snd_seq_t *handle, int q, snd_seq_queue_timer_t *timer);
int snd_seq_set_queue_timer(snd_seq_t *handle, int q, snd_seq_queue_timer_t *timer);
int snd_seq_get_queue_sync(snd_seq_t *handle, int q, snd_seq_queue_sync_t *sync);
int snd_seq_set_queue_sync(snd_seq_t *handle, int q, snd_seq_queue_sync_t *sync);
int snd_seq_get_queue_client(snd_seq_t *handle, int q, snd_seq_queue_client_t *queue);
int snd_seq_set_queue_client(snd_seq_t *handle, int q, snd_seq_queue_client_t *queue);
int snd_seq_alloc_queue(snd_seq_t *handle);
int snd_seq_free_queue(snd_seq_t *handle, int q);
int snd_seq_get_client_pool(snd_seq_t *handle, snd_seq_client_pool_t * info);
int snd_seq_set_client_pool(snd_seq_t *handle, snd_seq_client_pool_t * info);
/* event routines */
snd_seq_event_t *snd_seq_create_event(void);
int snd_seq_free_event(snd_seq_event_t *ev);
int snd_seq_event_length(snd_seq_event_t *ev);
int snd_seq_event_output(snd_seq_t *handle, snd_seq_event_t *ev);
int snd_seq_event_input(snd_seq_t *handle, snd_seq_event_t **ev);
int snd_seq_flush_output(snd_seq_t *handle);
int snd_seq_drain_output(snd_seq_t *handle);
int snd_seq_drain_input(snd_seq_t *handle);
/* misc */
void snd_seq_set_bit(int nr, void *array);
int snd_seq_change_bit(int nr, void *array);
int snd_seq_get_bit(int nr, void *array);

#ifdef __cplusplus
}
#endif

/****************************************************************************
 *                                                                          *
 *                                conv.h                                    *
 *                        Binary Value Conversion                           *
 *                                                                          *
 ****************************************************************************/

#ifdef SND_LITTLE_ENDIAN

#define snd_host_to_LE_16(val)	(val)
#define snd_LE_to_host_16(val)	(val)
#define snd_host_to_LE_32(val)	(val)
#define snd_LE_to_host_32(val)	(val)
#define snd_host_to_BE_16(val)	((((val)>>8)&0xff)|(((val)<<8)&0xff00))
#define snd_BE_to_host_16(val)	snd_host_to_BE_16(val)
#define snd_host_to_BE_32(val)	((((val)>>24)&0xff)|(((val)>>16)&0xff00)|\
                                 (((val)<<16)&0xff0000)|(((val)<<24)&0xff000000))
#define snd_BE_to_host_32(val)	snd_host_to_BE_32(val)

#else                                      

#define snd_host_to_BE_16(val)	(val)
#define snd_BE_to_host_16(val)	(val)
#define snd_host_to_BE_16(val)	(val)
#define snd_BE_to_host_16(val)	(val)
#define snd_host_to_LE_16(val)	((((val)>>8)&0xff)|(((val)<<8)&0xff00))
#define snd_LE_to_host_16(val)	snd_host_to_LE_16(val)
#define snd_host_to_LE_32(val)	((((val)>>24)&0xff)|(((val)>>16)&0xff00)|\
                                 (((val)<<16)&0xff0000)|(((val)<<24)&0xff000000))
#define snd_LE_to_host_32(val)	snd_host_to_LE_32(val)

#endif

/****************************************************************************
 *                                                                          *
 *                               instr.h                                    *
 *                          Instrument Interface                            *
 *                                                                          *
 ****************************************************************************/

/* Simple Wave support */

typedef void snd_instr_simple_t;

#ifdef __cplusplus
extern "C" {
#endif

int snd_instr_simple_convert_to_stream(snd_instr_simple_t *simple, const char *name, snd_seq_instr_put_t **put, long *size);
int snd_instr_simple_convert_from_stream(snd_seq_instr_get_t *data, long size, snd_instr_simple_t **simple);
int snd_instr_simple_free(snd_instr_simple_t *simple);

#ifdef __cplusplus
}
#endif

/* InterWave FFFF support */

typedef void snd_instr_iwffff_t;
typedef struct snd_iwffff_handle snd_iwffff_handle_t;

#ifdef __cplusplus
extern "C" {
#endif

int snd_instr_iwffff_open(snd_iwffff_handle_t **handle, const char *name_fff, const char *name_dta);
int snd_instr_iwffff_open_rom(snd_iwffff_handle_t **handle, int card, int bank, int file);
int snd_instr_iwffff_open_rom_file(snd_iwffff_handle_t **handle, const char *name, int bank, int file);
int snd_instr_iwffff_close(snd_iwffff_handle_t *handle);
int snd_instr_iwffff_load(snd_iwffff_handle_t *handle, int bank, int prg, snd_instr_iwffff_t **iwffff);
int snd_instr_iwffff_convert_to_stream(snd_instr_iwffff_t *iwffff, const char *name, snd_seq_instr_put_t **data, long *size);
int snd_instr_iwffff_convert_from_stream(snd_seq_instr_get_t *data, long size, snd_instr_iwffff_t **iwffff);
int snd_instr_iwffff_free(snd_instr_iwffff_t *iwffff);

#ifdef __cplusplus
}
#endif

/*
 *
 */
 
#endif /* __ASOUNDLIB_H */
