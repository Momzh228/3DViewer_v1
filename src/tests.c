#include <check.h>

#include "parser.h"
#include "parser_utility.h"
#include "transformations.h"

#define EPS 1e-06

START_TEST(affine_move_X_1) {
  data_gg test;
  const char *filename = "obj/pyramid.obj";
  int error = parse_obj(filename, &test);
  double vertices_arr[15] = {0 + 1, 1,     0, -1 + 1, 0,      -1, 1 + 1, 0,
                             -1,    1 + 1, 0, 1,      -1 + 1, 0,  1};
  ck_assert_int_eq(error, NO_ERROR);
  move_X(&test, 1);
  for (int i = 0; i < 15; i++) {
    ck_assert_double_eq_tol(test.vertex[i], vertices_arr[i], EPS);
  }
  free_data_gg(&test);
}
END_TEST

START_TEST(affine_move_Y_1) {
  data_gg test;
  const char *filename = "obj/pyramid.obj";
  int error = parse_obj(filename, &test);
  double vertices_arr[15] = {0,  1 + 1, 0,     -1, 0 + 1, -1,    1, 0 + 1,
                             -1, 1,     0 + 1, 1,  -1,    0 + 1, 1};
  ck_assert_int_eq(error, NO_ERROR);
  move_Y(&test, 1);
  for (int i = 0; i < 15; i++) {
    ck_assert_double_eq_tol(test.vertex[i], vertices_arr[i], EPS);
  }
  free_data_gg(&test);
}
END_TEST

START_TEST(affine_move_Z_1) {
  data_gg test;
  const char *filename = "obj/pyramid.obj";
  int error = parse_obj(filename, &test);
  double vertices_arr[15] = {0,      1, 0 + 1, -1,    0,  -1 + 1, 1,    0,
                             -1 + 1, 1, 0,     1 + 1, -1, 0,      1 + 1};
  ck_assert_int_eq(error, NO_ERROR);
  move_Z(&test, 1);
  for (int i = 0; i < 15; i++) {
    ck_assert_double_eq_tol(test.vertex[i], vertices_arr[i], EPS);
  }
  free_data_gg(&test);
}
END_TEST

START_TEST(affine_Rotation_X_1) {
  data_gg test;
  const char *filename = "obj/pyramid.obj";
  int error = parse_obj(filename, &test);
  double angle = convertAngleToRadians(1);
  double vertices_arr[15] = {0,           cos(angle),  sin(angle),  -1,
                             sin(angle),  -cos(angle), 1,           sin(angle),
                             -cos(angle), 1,           -sin(angle), cos(angle),
                             -1,          -sin(angle), cos(angle)};
  ck_assert_int_eq(error, NO_ERROR);
  rotate_X(&test, 1);
  for (int i = 0; i < 15; i++) {
    ck_assert_double_eq_tol(test.vertex[i], vertices_arr[i], EPS);
  }
  free_data_gg(&test);
}
END_TEST

START_TEST(affine_Rotation_Y_1) {
  data_gg test;
  const char *filename = "obj/pyramid.obj";
  int error = parse_obj(filename, &test);
  double angle = convertAngleToRadians(1);
  double vertices_arr[15] = {0,
                             1,
                             0,
                             -cos(angle) - sin(angle),
                             0,
                             -cos(angle) + sin(angle),
                             cos(angle) - sin(angle),
                             0,
                             -cos(angle) - sin(angle),
                             cos(angle) + sin(angle),
                             0,
                             cos(angle) - sin(angle),
                             -cos(angle) + sin(angle),
                             0,
                             cos(angle) + sin(angle)};
  ck_assert_int_eq(error, NO_ERROR);
  rotate_Y(&test, 1);
  for (int i = 0; i < 15; i++) {
    ck_assert_double_eq_tol(test.vertex[i], vertices_arr[i], EPS);
  }
  free_data_gg(&test);
}
END_TEST

START_TEST(affine_Rotation_Z_1) {
  data_gg test;
  const char *filename = "obj/pyramid.obj";
  double angle = convertAngleToRadians(1);
  int error = parse_obj(filename, &test);
  double vertices_arr[15] = {-sin(angle), cos(angle),  0,          -cos(angle),
                             -sin(angle), -1,          cos(angle), sin(angle),
                             -1,          cos(angle),  sin(angle), 1,
                             -cos(angle), -sin(angle), 1};
  ck_assert_int_eq(error, NO_ERROR);
  rotate_Z(&test, 1);
  for (int i = 0; i < 15; i++) {
    ck_assert_double_eq_tol(test.vertex[i], vertices_arr[i], EPS);
  }
  free_data_gg(&test);
}
END_TEST

START_TEST(affine_scale_1) {
  data_gg test;
  const char *filename = "obj/pyramid.obj";
  int error = parse_obj(filename, &test);
  double vertices_arr[15] = {0,       1 * 10, 0,       -1 * 10, 0,
                             -1 * 10, 1 * 10, 0,       -1 * 10, 1 * 10,
                             0,       1 * 10, -1 * 10, 0,       1 * 10};
  ck_assert_int_eq(error, NO_ERROR);
  scale(&test, 10);
  for (int i = 0; i < 15; i++) {
    ck_assert_double_eq_tol(test.vertex[i], vertices_arr[i], EPS);
  }
  free_data_gg(&test);
}
END_TEST

/* START_TEST(affine_scale_2) { */
/*   Objects obj = {0, NULL, NULL}; */
/*   const char *filename = "ObjFiles/cube.obj"; */
/*   s21_3DViewer(filename, &obj); */
/*   double vertices_arr[8][3] = {{3.0000000, 3.0000000, 3.0000000}, */
/*                                {3.0000000, 3.0000000, -3.0000000}, */
/*                                {3.0000000, -3.0000000, 3.0000000}, */
/*                                {3.0000000, -3.0000000, -3.0000000}, */
/*                                {-3.0000000, 3.0000000, 3.0000000}, */
/*                                {-3.0000000, 3.0000000, -3.0000000}, */
/*                                {-3.0000000, -3.0000000, 3.0000000}, */
/*                                {-3.0000000, -3.0000000, -3.0000000}}; */
/*   s21_mult_number(obj.vertic, -3); */
/*   ck_assert_int_eq(obj.vertic->rows, 8); */

/*   for (int i = 0; i < 8; i++) { */
/*     for (int j = 0; j < 3; j++) */
/*       ck_assert_double_eq_tol(obj.vertic->val[i][j], vertices_arr[i][j],
 * EPS); */
/*   } */
/*   StructureCleaning(&obj); */
/* } */
/* END_TEST */

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("Check");

  TCase *tc_affine_move_X_1;
  tc_affine_move_X_1 = tcase_create("affine_move_X_1");
  suite_add_tcase(s, tc_affine_move_X_1);
  tcase_add_test(tc_affine_move_X_1, affine_move_X_1);

  TCase *tc_affine_move_Y_1;
  tc_affine_move_Y_1 = tcase_create("affine_move_Y_1");
  suite_add_tcase(s, tc_affine_move_Y_1);
  tcase_add_test(tc_affine_move_Y_1, affine_move_Y_1);

  TCase *tc_affine_move_Z_1;
  tc_affine_move_Z_1 = tcase_create("affine_move_Z_1");
  suite_add_tcase(s, tc_affine_move_Z_1);
  tcase_add_test(tc_affine_move_Z_1, affine_move_Z_1);

  TCase *tc_affine_Rotation_X_1;
  tc_affine_Rotation_X_1 = tcase_create("affine_Rotation_X_1");
  suite_add_tcase(s, tc_affine_Rotation_X_1);
  tcase_add_test(tc_affine_Rotation_X_1, affine_Rotation_X_1);

  TCase *tc_affine_Rotation_Y_1;
  tc_affine_Rotation_Y_1 = tcase_create("affine_Rotation_Y_1");
  suite_add_tcase(s, tc_affine_Rotation_Y_1);
  tcase_add_test(tc_affine_Rotation_Y_1, affine_Rotation_Y_1);

  TCase *tc_affine_Rotation_Z_1;
  tc_affine_Rotation_Z_1 = tcase_create("affine_Rotation_Z_1");
  suite_add_tcase(s, tc_affine_Rotation_Z_1);
  tcase_add_test(tc_affine_Rotation_Z_1, affine_Rotation_Z_1);

  TCase *tc_affine_scale_1;
  tc_affine_scale_1 = tcase_create("affine_scale_1");
  suite_add_tcase(s, tc_affine_scale_1);
  tcase_add_test(tc_affine_scale_1, affine_scale_1);

  return s;
}

START_TEST(parser_vertices) {
  data_gg obj = {0};
  const char *filename = "obj/pyramid.obj";
  parse_obj(filename, &obj);
  double vertices_arr[][3] = {
      {0.0, 1.0, 0.0}, {-1.0, 0.0, -1.0}, {1.0, 0.0, -1.0},
      {1.0, 0.0, 1.0}, {-1.0, 0.0, 1.0},
  };
  ck_assert_int_eq(obj.vertex_count, 5);

  for (unsigned int i = 0; i < obj.vertex_count; i++) {
    for (unsigned int j = 0; j < 3; j++)
      ck_assert_double_eq_tol(obj.vertex[i * 3 + j], vertices_arr[i][j], EPS);
  }
  free_data_gg(&obj);
}
END_TEST

START_TEST(parser_indexes) {
  data_t obj = {0};
  const char *filename = "obj/pyramid.obj";
  vector_vertex_create(&obj);
  vector_index_create(&obj);
  parse_file(filename, &obj);
  double vertices_arr[][5] = {{0, 1, 2}, {0},       {0},       {0, 2, 3},
                              {0, 3, 4}, {0, 4, 1}, {2, 1, 3}, {1, 4, 3}};
  ck_assert_int_eq(obj.index_offset, 8);

  for (unsigned int i = 0; i < obj.index_count; i++) {
    for (int j = 0; j < obj.indexes[i].count; j++)
      ck_assert_double_eq_tol(obj.indexes[i].indexes[j], vertices_arr[i][j],
                              EPS);
  }
  vector_vertex_remove(&obj);
  vector_index_remove(&obj);
}
END_TEST

START_TEST(parser_finalized) {
  data_gg obj = {0};
  const char *filename = "obj/pyramid.obj";
  parse_obj(filename, &obj);
  double vertices_arr[][5] = {
      {0, 1}, {1, 2}, {2, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
      {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 2},
      {2, 3}, {3, 0}, {0, 0}, {0, 0}, {0, 3}, {3, 4}, {4, 0}, {0, 0},
      {0, 0}, {0, 4}, {4, 1}, {1, 0}, {0, 0}, {0, 0}, {2, 1}, {1, 3},
      {3, 2}, {0, 0}, {0, 0}, {1, 4}, {4, 3}, {3, 1}, {0, 0}, {0, 0}};
  ck_assert_int_eq(obj.edge_count, 20);
  ck_assert_int_eq(obj.index_count, 80);

  for (unsigned int i = 0; i < obj.index_count; i += 2) {
    ck_assert_int_eq(obj.index[i], vertices_arr[i / 2][0]);
    ck_assert_int_eq(obj.index[i + 1], vertices_arr[i / 2][1]);
  }
  free_data_gg(&obj);
}
END_TEST

Suite *parser_suite(void) {
  Suite *s;
  s = suite_create("Check");

  TCase *parser_vertices_tc;
  parser_vertices_tc = tcase_create("parser_vertices");
  suite_add_tcase(s, parser_vertices_tc);
  tcase_add_test(parser_vertices_tc, parser_vertices);
  TCase *parser_indexes_tc;
  parser_indexes_tc = tcase_create("parser_vertices");
  suite_add_tcase(s, parser_indexes_tc);
  tcase_add_test(parser_indexes_tc, parser_indexes);
  TCase *parser_finalized_tc;
  parser_finalized_tc = tcase_create("parser_vertices");
  suite_add_tcase(s, parser_finalized_tc);
  tcase_add_test(parser_finalized_tc, parser_finalized);

  return s;
}

int main(void) {
  Suite *s, *p;
  SRunner *sr, *sp;
  s = lib_suite();
  p = parser_suite();
  sr = srunner_create(s);
  sp = srunner_create(p);
  srunner_run_all(sr, CK_NORMAL);
  srunner_run_all(sp, CK_NORMAL);
  srunner_free(sr);
  srunner_free(sp);
  return 0;
}
