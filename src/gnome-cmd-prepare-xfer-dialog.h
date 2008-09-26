/*
    GNOME Commander - A GNOME based file manager
    Copyright (C) 2001-2006 Marcus Bjurman
    Copyright (C) 2007-2008 Piotr Eljasiak

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
*/
#ifndef __GNOME_CMD_PREPARE_XFER_DIALOG_H__
#define __GNOME_CMD_PREPARE_XFER_DIALOG_H__

#include "gnome-cmd-dir.h"
#include "gnome-cmd-file-list.h"
#include "gnome-cmd-file-selector.h"

#define GNOME_CMD_PREPARE_XFER_DIALOG(obj) \
    GTK_CHECK_CAST (obj, gnome_cmd_prepare_xfer_dialog_get_type (), GnomeCmdPrepareXferDialog)
#define GNOME_CMD_PREPARE_XFER_DIALOG_CLASS(klass) \
    GTK_CHECK_CLASS_CAST (klass, gnome_cmd_prepare_xfer_dialog_get_type (), GnomeCmdPrepareXferDialogClass)
#define GNOME_CMD_IS_PREPARE_XFER_DIALOG(obj) \
    GTK_CHECK_TYPE (obj, gnome_cmd_prepare_xfer_dialog_get_type ())


typedef struct _GnomeCmdPrepareXferDialog GnomeCmdPrepareXferDialog;
typedef struct _GnomeCmdPrepareXferDialogClass GnomeCmdPrepareXferDialogClass;



struct _GnomeCmdPrepareXferDialog
{
    GnomeCmdDialog parent;

    GtkWidget *dest_dir_frame;
    GtkWidget *dest_dir_entry;
    GtkWidget *left_vbox;
    GtkWidget *right_vbox;
    GtkWidget *left_vbox_frame;
    GtkWidget *right_vbox_frame;
    GtkWidget *ok_button;
    GtkWidget *cancel_button;

    GnomeVFSXferOptions xferOptions;
    GnomeVFSXferOverwriteMode xferOverwriteMode;

    GList *src_files;
    GnomeCmdFileSelector *src_fs;
    GnomeCmdDir *default_dest_dir;
};


struct _GnomeCmdPrepareXferDialogClass
{
    GnomeCmdDialogClass parent_class;
};


GtkWidget*
gnome_cmd_prepare_xfer_dialog_new (GnomeCmdFileSelector *from,
                                   GnomeCmdFileSelector *to);

GtkType
gnome_cmd_prepare_xfer_dialog_get_type ();

#endif // __GNOME_CMD_PREPARE_XFER_DIALOG_H__
