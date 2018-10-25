# News

There was a small error in the documentation (.h) files first posted. They have been corrected on Oct 25th at 7am, so if you downloaded the .zip file prior to that, please re-download.

# Frequently Asked Questions

* Why does bmp_close need to take "unsigned char **img_data" instead of a single pointer?

   A: Note the documentation states the pointer must be set to NULL. That means the pointer in the calling function. This is a case of passing a pointer by reference, which extends the idea of passing typical variables by reference, we need to use a pointer to change the value outside the function.
