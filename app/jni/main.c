// Copyright 2014-2015 The GTK+Android Developers. See the COPYRIGHT
// file at the top-level directory of this distribution and at
// https://github.com/eugals/GTKAndroid/wiki/COPYRIGHT.
//
// Licensed under the Apache License, Version 2.0 <LICENSE-APACHE or
// http://www.apache.org/licenses/LICENSE-2.0> or the MIT license
// <LICENSE-MIT or http://opensource.org/licenses/MIT>, at your
// option. This file may not be copied, modified, or distributed
// except according to those terms.
//
// Author(s): Evgeny Sologubov
//
// GTK+Android test application

#include <jni.h>
#include <errno.h>

#include <android_native_app_glue.h>

#include <gtkandroid.h>

/*
static void hello(GtkWidget *widget, gpointer data)
{
    GtkWidget *box = (GtkWidget *) data;
    GtkWidget *label = gtk_label_new("Hello!");
    gtk_container_add(GTK_CONTAINER(box), label);
    gtk_widget_show(label);
}

static void quit_gtk(GtkWidget *widget, gpointer data)
{
    g_info("quit!");
    gtk_main_quit();
}


void android_main(struct android_app *state)
{
	GtkWidget *window, *vbox, *hbox, *halign, *valign,*edit, *button, *label;

    g_usleep(5 * 1000000);
    gtk_android_init(state);
	g_usleep(3 * 1000000);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_maximize(GTK_WINDOW(window));
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 25);
    valign = gtk_alignment_new(0, 1, 0, 0);
    gtk_container_add(GTK_CONTAINER(vbox), valign);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    edit = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(edit), "Hello world");
    gtk_container_add(GTK_CONTAINER(vbox), edit);
    button = gtk_button_new_with_label("Say Hello");
    gtk_widget_set_size_request(button, 200, 100);
    gtk_container_add(GTK_CONTAINER(vbox), button);
    g_signal_connect(button, "clicked", G_CALLBACK(hello), vbox);
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    button = gtk_button_new_with_label("Quit");
    gtk_widget_set_size_request(button, 200, 100);
    gtk_container_add(GTK_CONTAINER(hbox), button);
    g_signal_connect(button, "clicked", G_CALLBACK(quit_gtk), NULL);
    halign = gtk_alignment_new(1, 0, 0, 0);
    gtk_container_add(GTK_CONTAINER(halign), hbox);
    gtk_box_pack_end(GTK_BOX(vbox), halign, FALSE, FALSE, 0);

    //g_signal_connect_swapped(G_OBJECT(window), "destroy",
    //    G_CALLBACK(gtk_main_quit), G_OBJECT(window));

    gtk_widget_show_all(window);

    gtk_main();

    // Finish the activity and makes sure it is properly unloaded
    gtk_android_exit(state);
}*/


void hello(GtkWidget * widget,gpointer *data)
{
	g_printf("button clicked and data = %s\n",(char *)data);
}

gint delete_event(GtkWidget * widget,GdkEvent *event,gpointer data)
{
	g_print("delete event occurred\n");
	return FALSE;
}

void destroy(GtkWidget *widget,gpointer *data)
{
	gtk_main_quit();
}


void android_main(struct android_app *state)
{
	struct android_app *stateS = NULL;
	GtkWidget *window;
	GtkWidget * button;
	//gtk_init(&argc,&argv);
	g_usleep(5 * 1000000);
    gtk_android_init(stateS);
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"TEST GTK FOR ANDROID");
	//g_signal_connect(GTK_OBJECT(window),"delete_event",GTK_SIGNAL_FUNC(delete_event),NULL);
	//gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(destroy),NULL);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	button = gtk_button_new_with_label("Hello World");
	g_signal_connect(button,"clicked",G_CALLBACK(hello),"HELLO WORLD");
	g_signal_connect(button,"clicked",G_CALLBACK(gtk_widget_destroy),G_CALLBACK(window));
	gtk_container_add(GTK_CONTAINER(window),button);
	gtk_widget_show(button);
	gtk_widget_show(window);
	gtk_main();

}


