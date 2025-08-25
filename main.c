// #include <gtk/gtk.h>
#include <adwaita.h>
#include <stdio.h>


static void
activate_cb (GtkApplication *app)
{
  GtkWidget *window = gtk_application_window_new (app);
  GtkWidget *page = adw_status_page_new ();

  GtkWidget *popover = gtk_popover_new ();
  GtkWidget *text = gtk_text_new ();
  GtkWidget *button = gtk_menu_button_new ();

  gtk_text_set_placeholder_text((GtkText *)text, "foobar");
  gtk_popover_set_child((GtkPopover *)popover, text);
  gtk_menu_button_set_popover((GtkMenuButton *)button, popover);
  adw_status_page_set_child((AdwStatusPage *)page, button);

  gtk_window_set_title (GTK_WINDOW (window), "Hello");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  gtk_window_set_child (GTK_WINDOW (window), (GtkWidget *)page);
  gtk_window_present (GTK_WINDOW (window));
}

int
main (int   argc,
      char *argv[])
{
  g_autoptr (AdwApplication) app = NULL;

  app = adw_application_new ("org.example.Hello", G_APPLICATION_FLAGS_NONE);

  g_signal_connect (app, "activate", G_CALLBACK (activate_cb), NULL);

  return g_application_run (G_APPLICATION (app), argc, argv);
}
