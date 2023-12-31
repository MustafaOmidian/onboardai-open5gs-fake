
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nwdaf_registration.h"

OpenAPI_nwdaf_registration_t *OpenAPI_nwdaf_registration_create(
    char *nwdaf_instance_id,
    OpenAPI_list_t *analytics_ids,
    char *nwdaf_set_id,
    char *registration_time,
    OpenAPI_context_info_t *context_info,
    char *supported_features,
    OpenAPI_list_t *reset_ids
)
{
    OpenAPI_nwdaf_registration_t *nwdaf_registration_local_var = ogs_malloc(sizeof(OpenAPI_nwdaf_registration_t));
    ogs_assert(nwdaf_registration_local_var);

    nwdaf_registration_local_var->nwdaf_instance_id = nwdaf_instance_id;
    nwdaf_registration_local_var->analytics_ids = analytics_ids;
    nwdaf_registration_local_var->nwdaf_set_id = nwdaf_set_id;
    nwdaf_registration_local_var->registration_time = registration_time;
    nwdaf_registration_local_var->context_info = context_info;
    nwdaf_registration_local_var->supported_features = supported_features;
    nwdaf_registration_local_var->reset_ids = reset_ids;

    return nwdaf_registration_local_var;
}

void OpenAPI_nwdaf_registration_free(OpenAPI_nwdaf_registration_t *nwdaf_registration)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == nwdaf_registration) {
        return;
    }
    if (nwdaf_registration->nwdaf_instance_id) {
        ogs_free(nwdaf_registration->nwdaf_instance_id);
        nwdaf_registration->nwdaf_instance_id = NULL;
    }
    if (nwdaf_registration->analytics_ids) {
        OpenAPI_list_for_each(nwdaf_registration->analytics_ids, node) {
            OpenAPI_event_id_free(node->data);
        }
        OpenAPI_list_free(nwdaf_registration->analytics_ids);
        nwdaf_registration->analytics_ids = NULL;
    }
    if (nwdaf_registration->nwdaf_set_id) {
        ogs_free(nwdaf_registration->nwdaf_set_id);
        nwdaf_registration->nwdaf_set_id = NULL;
    }
    if (nwdaf_registration->registration_time) {
        ogs_free(nwdaf_registration->registration_time);
        nwdaf_registration->registration_time = NULL;
    }
    if (nwdaf_registration->context_info) {
        OpenAPI_context_info_free(nwdaf_registration->context_info);
        nwdaf_registration->context_info = NULL;
    }
    if (nwdaf_registration->supported_features) {
        ogs_free(nwdaf_registration->supported_features);
        nwdaf_registration->supported_features = NULL;
    }
    if (nwdaf_registration->reset_ids) {
        OpenAPI_list_for_each(nwdaf_registration->reset_ids, node) {
            ogs_free(node->data);
        }
        OpenAPI_list_free(nwdaf_registration->reset_ids);
        nwdaf_registration->reset_ids = NULL;
    }
    ogs_free(nwdaf_registration);
}

cJSON *OpenAPI_nwdaf_registration_convertToJSON(OpenAPI_nwdaf_registration_t *nwdaf_registration)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (nwdaf_registration == NULL) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [NwdafRegistration]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!nwdaf_registration->nwdaf_instance_id) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [nwdaf_instance_id]");
        return NULL;
    }
    if (cJSON_AddStringToObject(item, "nwdafInstanceId", nwdaf_registration->nwdaf_instance_id) == NULL) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [nwdaf_instance_id]");
        goto end;
    }

    if (!nwdaf_registration->analytics_ids) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [analytics_ids]");
        return NULL;
    }
    cJSON *analytics_idsList = cJSON_AddArrayToObject(item, "analyticsIds");
    if (analytics_idsList == NULL) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [analytics_ids]");
        goto end;
    }
    OpenAPI_list_for_each(nwdaf_registration->analytics_ids, node) {
        cJSON *itemLocal = OpenAPI_event_id_convertToJSON(node->data);
        if (itemLocal == NULL) {
            ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [analytics_ids]");
            goto end;
        }
        cJSON_AddItemToArray(analytics_idsList, itemLocal);
    }

    if (nwdaf_registration->nwdaf_set_id) {
    if (cJSON_AddStringToObject(item, "nwdafSetId", nwdaf_registration->nwdaf_set_id) == NULL) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [nwdaf_set_id]");
        goto end;
    }
    }

    if (nwdaf_registration->registration_time) {
    if (cJSON_AddStringToObject(item, "registrationTime", nwdaf_registration->registration_time) == NULL) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [registration_time]");
        goto end;
    }
    }

    if (nwdaf_registration->context_info) {
    cJSON *context_info_local_JSON = OpenAPI_context_info_convertToJSON(nwdaf_registration->context_info);
    if (context_info_local_JSON == NULL) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [context_info]");
        goto end;
    }
    cJSON_AddItemToObject(item, "contextInfo", context_info_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [context_info]");
        goto end;
    }
    }

    if (nwdaf_registration->supported_features) {
    if (cJSON_AddStringToObject(item, "supportedFeatures", nwdaf_registration->supported_features) == NULL) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [supported_features]");
        goto end;
    }
    }

    if (nwdaf_registration->reset_ids) {
    cJSON *reset_idsList = cJSON_AddArrayToObject(item, "resetIds");
    if (reset_idsList == NULL) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [reset_ids]");
        goto end;
    }
    OpenAPI_list_for_each(nwdaf_registration->reset_ids, node) {
        if (cJSON_AddStringToObject(reset_idsList, "", (char*)node->data) == NULL) {
            ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed [reset_ids]");
            goto end;
        }
    }
    }

end:
    return item;
}

OpenAPI_nwdaf_registration_t *OpenAPI_nwdaf_registration_parseFromJSON(cJSON *nwdaf_registrationJSON)
{
    OpenAPI_nwdaf_registration_t *nwdaf_registration_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *nwdaf_instance_id = NULL;
    cJSON *analytics_ids = NULL;
    OpenAPI_list_t *analytics_idsList = NULL;
    cJSON *nwdaf_set_id = NULL;
    cJSON *registration_time = NULL;
    cJSON *context_info = NULL;
    OpenAPI_context_info_t *context_info_local_nonprim = NULL;
    cJSON *supported_features = NULL;
    cJSON *reset_ids = NULL;
    OpenAPI_list_t *reset_idsList = NULL;
    nwdaf_instance_id = cJSON_GetObjectItemCaseSensitive(nwdaf_registrationJSON, "nwdafInstanceId");
    if (!nwdaf_instance_id) {
        ogs_error("OpenAPI_nwdaf_registration_parseFromJSON() failed [nwdaf_instance_id]");
        goto end;
    }
    if (!cJSON_IsString(nwdaf_instance_id)) {
        ogs_error("OpenAPI_nwdaf_registration_parseFromJSON() failed [nwdaf_instance_id]");
        goto end;
    }

    analytics_ids = cJSON_GetObjectItemCaseSensitive(nwdaf_registrationJSON, "analyticsIds");
    if (!analytics_ids) {
        ogs_error("OpenAPI_nwdaf_registration_parseFromJSON() failed [analytics_ids]");
        goto end;
    }
        cJSON *analytics_ids_local = NULL;
        if (!cJSON_IsArray(analytics_ids)) {
            ogs_error("OpenAPI_nwdaf_registration_parseFromJSON() failed [analytics_ids]");
            goto end;
        }

        analytics_idsList = OpenAPI_list_create();

        cJSON_ArrayForEach(analytics_ids_local, analytics_ids) {
            if (!cJSON_IsObject(analytics_ids_local)) {
                ogs_error("OpenAPI_nwdaf_registration_parseFromJSON() failed [analytics_ids]");
                goto end;
            }
            OpenAPI_event_id_t *analytics_idsItem = OpenAPI_event_id_parseFromJSON(analytics_ids_local);
            if (!analytics_idsItem) {
                ogs_error("No analytics_idsItem");
                goto end;
            }
            OpenAPI_list_add(analytics_idsList, analytics_idsItem);
        }

    nwdaf_set_id = cJSON_GetObjectItemCaseSensitive(nwdaf_registrationJSON, "nwdafSetId");
    if (nwdaf_set_id) {
    if (!cJSON_IsString(nwdaf_set_id) && !cJSON_IsNull(nwdaf_set_id)) {
        ogs_error("OpenAPI_nwdaf_registration_parseFromJSON() failed [nwdaf_set_id]");
        goto end;
    }
    }

    registration_time = cJSON_GetObjectItemCaseSensitive(nwdaf_registrationJSON, "registrationTime");
    if (registration_time) {
    if (!cJSON_IsString(registration_time) && !cJSON_IsNull(registration_time)) {
        ogs_error("OpenAPI_nwdaf_registration_parseFromJSON() failed [registration_time]");
        goto end;
    }
    }

    context_info = cJSON_GetObjectItemCaseSensitive(nwdaf_registrationJSON, "contextInfo");
    if (context_info) {
    context_info_local_nonprim = OpenAPI_context_info_parseFromJSON(context_info);
    if (!context_info_local_nonprim) {
        ogs_error("OpenAPI_context_info_parseFromJSON failed [context_info]");
        goto end;
    }
    }

    supported_features = cJSON_GetObjectItemCaseSensitive(nwdaf_registrationJSON, "supportedFeatures");
    if (supported_features) {
    if (!cJSON_IsString(supported_features) && !cJSON_IsNull(supported_features)) {
        ogs_error("OpenAPI_nwdaf_registration_parseFromJSON() failed [supported_features]");
        goto end;
    }
    }

    reset_ids = cJSON_GetObjectItemCaseSensitive(nwdaf_registrationJSON, "resetIds");
    if (reset_ids) {
        cJSON *reset_ids_local = NULL;
        if (!cJSON_IsArray(reset_ids)) {
            ogs_error("OpenAPI_nwdaf_registration_parseFromJSON() failed [reset_ids]");
            goto end;
        }

        reset_idsList = OpenAPI_list_create();

        cJSON_ArrayForEach(reset_ids_local, reset_ids) {
            double *localDouble = NULL;
            int *localInt = NULL;
            if (!cJSON_IsString(reset_ids_local)) {
                ogs_error("OpenAPI_nwdaf_registration_parseFromJSON() failed [reset_ids]");
                goto end;
            }
            OpenAPI_list_add(reset_idsList, ogs_strdup(reset_ids_local->valuestring));
        }
    }

    nwdaf_registration_local_var = OpenAPI_nwdaf_registration_create (
        ogs_strdup(nwdaf_instance_id->valuestring),
        analytics_idsList,
        nwdaf_set_id && !cJSON_IsNull(nwdaf_set_id) ? ogs_strdup(nwdaf_set_id->valuestring) : NULL,
        registration_time && !cJSON_IsNull(registration_time) ? ogs_strdup(registration_time->valuestring) : NULL,
        context_info ? context_info_local_nonprim : NULL,
        supported_features && !cJSON_IsNull(supported_features) ? ogs_strdup(supported_features->valuestring) : NULL,
        reset_ids ? reset_idsList : NULL
    );

    return nwdaf_registration_local_var;
end:
    if (analytics_idsList) {
        OpenAPI_list_for_each(analytics_idsList, node) {
            OpenAPI_event_id_free(node->data);
        }
        OpenAPI_list_free(analytics_idsList);
        analytics_idsList = NULL;
    }
    if (context_info_local_nonprim) {
        OpenAPI_context_info_free(context_info_local_nonprim);
        context_info_local_nonprim = NULL;
    }
    if (reset_idsList) {
        OpenAPI_list_for_each(reset_idsList, node) {
            ogs_free(node->data);
        }
        OpenAPI_list_free(reset_idsList);
        reset_idsList = NULL;
    }
    return NULL;
}

OpenAPI_nwdaf_registration_t *OpenAPI_nwdaf_registration_copy(OpenAPI_nwdaf_registration_t *dst, OpenAPI_nwdaf_registration_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_nwdaf_registration_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_nwdaf_registration_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        ogs_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        ogs_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_nwdaf_registration_free(dst);
    dst = OpenAPI_nwdaf_registration_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

