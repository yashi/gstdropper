/* GStreamer
 * Copyright (C) 2013 Rdio <ingestions@rdio.com>
 * Copyright (C) 2013 David Schleef <ds@schleef.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Suite 500,
 * Boston, MA 02110-1335, USA.
 */
/**
 * SECTION:element-gstdropper
 *
 * The dropper element drops certain frame acording to the rules
 * given.
 *
 * <refsect2>
 * <title>Example launch line</title>
 * |[
 * gst-launch -v fakesrc ! dropper ! fakesink
 * ]|
 * </refsect2>
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gst/gst.h>
#include <gst/base/gstbasetransform.h>
#include "drop.h"

static GstStaticPadTemplate sinktemplate = GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS_ANY);

static GstStaticPadTemplate srctemplate = GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS_ANY);

GST_DEBUG_CATEGORY_STATIC (gst_dropper_debug_category);
#define GST_CAT_DEFAULT gst_dropper_debug_category

/* prototypes */

static GstFlowReturn gst_dropper_transform_ip (GstBaseTransform *trans,
					       GstBuffer        *buf);

/* class initialization */

G_DEFINE_TYPE_WITH_CODE (GstDropper, gst_dropper, GST_TYPE_BASE_TRANSFORM,
			 GST_DEBUG_CATEGORY_INIT (gst_dropper_debug_category, "dropper", 0,
						  "debug category for dropper element"));

static GstStateChangeReturn
gst_dropper_change_state (GstElement * element, GstStateChange transition);

static void
gst_dropper_class_init (GstDropperClass * klass)
{
	GstElementClass *gstelement_class;
	GstBaseTransformClass *gstbasetrans_class;

	gstelement_class = GST_ELEMENT_CLASS (klass);
	gstbasetrans_class = GST_BASE_TRANSFORM_CLASS (klass);

	gst_element_class_set_static_metadata (GST_ELEMENT_CLASS (klass),
					       "Dropper",
					       "Generic",
					       "Test dropper",
					       "Yasushi SHOJI <yashi@atmark-techno.com>");

	gst_element_class_add_pad_template (gstelement_class,
					    gst_static_pad_template_get (&srctemplate));
	gst_element_class_add_pad_template (gstelement_class,
					    gst_static_pad_template_get (&sinktemplate));

	gstelement_class->change_state =
		GST_DEBUG_FUNCPTR (gst_dropper_change_state);
	gstbasetrans_class->transform_ip =
		GST_DEBUG_FUNCPTR (gst_dropper_transform_ip);
}

static void
gst_dropper_init (GstDropper * dropper)
{
}

static GstFlowReturn
gst_dropper_transform_ip (GstBaseTransform * trans, GstBuffer * buf)
{
	GstDropper *dropper = GST_DROPPER (trans);

	GST_DEBUG_OBJECT (dropper, "transform_ip");

	GST_OBJECT_LOCK (dropper);

	GST_OBJECT_UNLOCK (dropper);

	return GST_FLOW_OK;
}

static GstStateChangeReturn
gst_dropper_change_state (GstElement * element, GstStateChange transition)
{
	GstStateChangeReturn ret = GST_STATE_CHANGE_SUCCESS;
	GstDropper *dropper = GST_DROPPER (element);

	GST_DEBUG_OBJECT (dropper, "gst_dropper_change_state");

	switch (transition) {
	case GST_STATE_CHANGE_PAUSED_TO_PLAYING:
		break;
	default:
		break;
	}

	ret = GST_ELEMENT_CLASS (gst_dropper_parent_class)->change_state (element,
									  transition);

	switch (transition) {
	case GST_STATE_CHANGE_READY_TO_PAUSED:
		break;
	case GST_STATE_CHANGE_PLAYING_TO_PAUSED:
		break;
	default:
		break;
	}

	return ret;
}
