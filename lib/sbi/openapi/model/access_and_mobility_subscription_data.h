/*
 * access_and_mobility_subscription_data.h
 *
 * 
 */

#ifndef _OpenAPI_access_and_mobility_subscription_data_H_
#define _OpenAPI_access_and_mobility_subscription_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "aerial_ue_subscription_info.h"
#include "ambr_rm.h"
#include "area.h"
#include "cag_data.h"
#include "core_network_type.h"
#include "ec_restriction_data_wb.h"
#include "edrx_parameters.h"
#include "expected_ue_behaviour_data.h"
#include "mdt_configuration.h"
#include "mdt_user_consent.h"
#include "nssai.h"
#include "odb_packet_services.h"
#include "pcf_selection_assistance_info.h"
#include "plmn_restriction.h"
#include "ptw_parameters.h"
#include "rat_type.h"
#include "roaming_restrictions.h"
#include "service_area_restriction.h"
#include "set.h"
#include "sor_info.h"
#include "sor_update_indicator.h"
#include "trace_data.h"
#include "upu_info.h"
#include "wireline_area.h"
#include "wireline_service_area_restriction.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_access_and_mobility_subscription_data_s OpenAPI_access_and_mobility_subscription_data_t;
typedef struct OpenAPI_access_and_mobility_subscription_data_s {
    char *supported_features;
    OpenAPI_list_t *gpsis;
    char *hss_group_id;
    OpenAPI_list_t *internal_group_ids;
    OpenAPI_list_t* shared_vn_group_data_ids;
    struct OpenAPI_ambr_rm_s *subscribed_ue_ambr;
    bool is_nssai_null;
    struct OpenAPI_nssai_s *nssai;
    OpenAPI_set_t *rat_restrictions;
    OpenAPI_list_t *forbidden_areas;
    struct OpenAPI_service_area_restriction_s *service_area_restriction;
    OpenAPI_list_t *core_network_type_restrictions;
    bool is_rfsp_index_null;
    bool is_rfsp_index;
    int rfsp_index;
    bool is_subs_reg_timer_null;
    bool is_subs_reg_timer;
    int subs_reg_timer;
    bool is_ue_usage_type;
    int ue_usage_type;
    bool is_mps_priority;
    int mps_priority;
    bool is_mcs_priority;
    int mcs_priority;
    bool is_active_time_null;
    bool is_active_time;
    int active_time;
    struct OpenAPI_sor_info_s *sor_info;
    bool is_sor_info_expect_ind;
    int sor_info_expect_ind;
    bool is_soraf_retrieval;
    int soraf_retrieval;
    OpenAPI_list_t *sor_update_indicator_list;
    struct OpenAPI_upu_info_s *upu_info;
    char *routing_indicator;
    bool is_mico_allowed;
    int mico_allowed;
    OpenAPI_list_t *shared_am_data_ids;
    OpenAPI_odb_packet_services_e odb_packet_services;
    OpenAPI_list_t *subscribed_dnn_list;
    bool is_service_gap_time;
    int service_gap_time;
    OpenAPI_mdt_user_consent_e mdt_user_consent;
    struct OpenAPI_mdt_configuration_s *mdt_configuration;
    bool is_trace_data_null;
    struct OpenAPI_trace_data_s *trace_data;
    struct OpenAPI_cag_data_s *cag_data;
    char *stn_sr;
    char *c_msisdn;
    bool is_nb_io_tue_priority;
    int nb_io_tue_priority;
    bool is_nssai_inclusion_allowed;
    int nssai_inclusion_allowed;
    char *rg_wireline_characteristics;
    struct OpenAPI_ec_restriction_data_wb_s *ec_restriction_data_wb;
    bool is_ec_restriction_data_nb;
    int ec_restriction_data_nb;
    struct OpenAPI_expected_ue_behaviour_data_s *expected_ue_behaviour_list;
    OpenAPI_set_t *primary_rat_restrictions;
    OpenAPI_set_t *secondary_rat_restrictions;
    OpenAPI_list_t *edrx_parameters_list;
    OpenAPI_list_t *ptw_parameters_list;
    bool is_iab_operation_allowed;
    int iab_operation_allowed;
    OpenAPI_list_t* adjacent_plmn_restrictions;
    OpenAPI_list_t *wireline_forbidden_areas;
    struct OpenAPI_wireline_service_area_restriction_s *wireline_service_area_restriction;
    OpenAPI_list_t *pcf_selection_assistance_infos;
    struct OpenAPI_aerial_ue_subscription_info_s *aerial_ue_sub_info;
    struct OpenAPI_roaming_restrictions_s *roaming_restrictions;
    bool is_remote_prov_ind;
    int remote_prov_ind;
} OpenAPI_access_and_mobility_subscription_data_t;

OpenAPI_access_and_mobility_subscription_data_t *OpenAPI_access_and_mobility_subscription_data_create(
    char *supported_features,
    OpenAPI_list_t *gpsis,
    char *hss_group_id,
    OpenAPI_list_t *internal_group_ids,
    OpenAPI_list_t* shared_vn_group_data_ids,
    OpenAPI_ambr_rm_t *subscribed_ue_ambr,
    bool is_nssai_null,
    OpenAPI_nssai_t *nssai,
    OpenAPI_set_t *rat_restrictions,
    OpenAPI_list_t *forbidden_areas,
    OpenAPI_service_area_restriction_t *service_area_restriction,
    OpenAPI_list_t *core_network_type_restrictions,
    bool is_rfsp_index_null,
    bool is_rfsp_index,
    int rfsp_index,
    bool is_subs_reg_timer_null,
    bool is_subs_reg_timer,
    int subs_reg_timer,
    bool is_ue_usage_type,
    int ue_usage_type,
    bool is_mps_priority,
    int mps_priority,
    bool is_mcs_priority,
    int mcs_priority,
    bool is_active_time_null,
    bool is_active_time,
    int active_time,
    OpenAPI_sor_info_t *sor_info,
    bool is_sor_info_expect_ind,
    int sor_info_expect_ind,
    bool is_soraf_retrieval,
    int soraf_retrieval,
    OpenAPI_list_t *sor_update_indicator_list,
    OpenAPI_upu_info_t *upu_info,
    char *routing_indicator,
    bool is_mico_allowed,
    int mico_allowed,
    OpenAPI_list_t *shared_am_data_ids,
    OpenAPI_odb_packet_services_e odb_packet_services,
    OpenAPI_list_t *subscribed_dnn_list,
    bool is_service_gap_time,
    int service_gap_time,
    OpenAPI_mdt_user_consent_e mdt_user_consent,
    OpenAPI_mdt_configuration_t *mdt_configuration,
    bool is_trace_data_null,
    OpenAPI_trace_data_t *trace_data,
    OpenAPI_cag_data_t *cag_data,
    char *stn_sr,
    char *c_msisdn,
    bool is_nb_io_tue_priority,
    int nb_io_tue_priority,
    bool is_nssai_inclusion_allowed,
    int nssai_inclusion_allowed,
    char *rg_wireline_characteristics,
    OpenAPI_ec_restriction_data_wb_t *ec_restriction_data_wb,
    bool is_ec_restriction_data_nb,
    int ec_restriction_data_nb,
    OpenAPI_expected_ue_behaviour_data_t *expected_ue_behaviour_list,
    OpenAPI_set_t *primary_rat_restrictions,
    OpenAPI_set_t *secondary_rat_restrictions,
    OpenAPI_list_t *edrx_parameters_list,
    OpenAPI_list_t *ptw_parameters_list,
    bool is_iab_operation_allowed,
    int iab_operation_allowed,
    OpenAPI_list_t* adjacent_plmn_restrictions,
    OpenAPI_list_t *wireline_forbidden_areas,
    OpenAPI_wireline_service_area_restriction_t *wireline_service_area_restriction,
    OpenAPI_list_t *pcf_selection_assistance_infos,
    OpenAPI_aerial_ue_subscription_info_t *aerial_ue_sub_info,
    OpenAPI_roaming_restrictions_t *roaming_restrictions,
    bool is_remote_prov_ind,
    int remote_prov_ind
);
void OpenAPI_access_and_mobility_subscription_data_free(OpenAPI_access_and_mobility_subscription_data_t *access_and_mobility_subscription_data);
OpenAPI_access_and_mobility_subscription_data_t *OpenAPI_access_and_mobility_subscription_data_parseFromJSON(cJSON *access_and_mobility_subscription_dataJSON);
cJSON *OpenAPI_access_and_mobility_subscription_data_convertToJSON(OpenAPI_access_and_mobility_subscription_data_t *access_and_mobility_subscription_data);
OpenAPI_access_and_mobility_subscription_data_t *OpenAPI_access_and_mobility_subscription_data_copy(OpenAPI_access_and_mobility_subscription_data_t *dst, OpenAPI_access_and_mobility_subscription_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_access_and_mobility_subscription_data_H_ */

