<?php

/**
 * @file
 * Fields CRUD functions.
 *
 */

/**
 * Adds body field to a paragraph bundle.
 *
 * @param string $bundle
 *   A paragraph type machine_name.
 * @param $field_label
 *   A label of the field.
 * @return array
 *   An items field instance.
 */
function paragraphs_pack_add_field_body($bundle, $field_label) {
  $field = paragraphs_pack_get_field_body();

  $instance = _paragraphs_pack_add_field(array(
    'field_name' => $field['field_name'],
    'entity_type' => CLASSY_PARAGRAPHS_ENTITY_TYPE,
    'bundle' => $bundle,
    'label' => $field_label,
    'widget' => array('type' => 'text_textarea_with_summary'),
    'settings' => array('display_summary' => TRUE),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'text_summary_or_trimmed',
      ),
    ),
  ));

  return $instance;
}

/**
 * Get/Create body field.
 *
 * This field can be used only on paragraph entity type.
 *
 * @return array
 *  An array containing field values.
 */
function paragraphs_pack_get_field_body() {
  $field = _paragraphs_pack_get_field(array(
    'field_name' => PP_FIELD_BODY,
    'type' => 'text_with_summary',
    'entity_types' => array(CLASSY_PARAGRAPHS_ENTITY_TYPE),
  ));

  return $field;
}

/**
 * Adds/Create field instance of PP_PARAGRAPH_TYPE.
 *
 * Helper function.
 *
 * @param array $instance
 *   An array of instance settings.
 * @return array
 *   An instance.
 */
function _paragraphs_pack_add_field($instance) {
  // Check if the instance exists already.
  $instance_info = field_info_instance(CLASSY_PARAGRAPHS_ENTITY_TYPE, $instance['field_name'], $instance['bundle']);
  if (empty($instance_info)) {
    field_create_instance($instance);
  }

  return $instance_info;
}

/**
 * Get/Create field by $field settings.
 *
 * Helper function.
 *
 * @param array $field
 *   An array of field settings.
 * @return array
 *   A field.
 */
function _paragraphs_pack_get_field($field) {
  // Check if the field exists already.
  $field_info = field_info_field($field['field_name']);
  if (empty($field_info)) {
    $field_info = field_create_field($field);
  }

  return $field_info;
}
