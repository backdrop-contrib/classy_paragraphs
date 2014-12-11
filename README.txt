Classy paragraphs ships a widget which allows an editor to apply a class to paragraphs via a List (text) field.

## How to use

Create a List (text) field and use the "Classy paragraphs select" widget. Classes are added by implementing the `hook_classy_paragraph_list_options`.

## How this module works

This module allows an editor to select a class which is then added to the paragraph template.

The class is added to the template via the `classy_paragraphs_preprocess_entity` preprocess function. In this function we use `classy_paragraphs_get_class` to pull out the selected class from the paragraph_item entity. Once we have a class, then we add it to the template using `$variables['classes_array']`.